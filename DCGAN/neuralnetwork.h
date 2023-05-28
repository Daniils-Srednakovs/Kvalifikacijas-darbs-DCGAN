#pragma once
#include <iostream>
#include <random>
#include <thread>
#include <fstream>
#include <functional>
#include <string>

#include "tensor.h"
#include "imagerw.h"

double normalDistribution(double mju = 0, double sigma = 1);

class nn
{
public:

	void printNeurons() { X.printTensorValues(); }
	Tensor3d<double>& getNeurons() { return X; }
	std::string getName() { return name; }
	void saveAllWeights();
	void loadAllWeights();
	void printKernels(size_t i) {
		layers[i - 1]->printKernelValues();
	}
	void printids() { for (auto layerr : layers) { layerr->printlayerid(); } };

protected:

	std::string name;
	Tensor3d<double> X;
	std::vector<Tensor3d<double>> l_outputs;

	double error = 0;

	virtual void countBatchError() = 0;
	virtual void forward(Tensor3d<double>& input) = 0;
	virtual void backward() = 0;
	virtual void countOuterGradient(size_t batch_i) = 0;

	class Layer
	{
	private:
		size_t layer_id;
		std::vector<Tensor3d<double>>* l_outputs;
		Tensor3d<double>* X;
		Tensor4d<double> V;
		Tensor4d<double> sum_dV;
		size_t i_ch; // in_channels
		size_t o_ch; // out_channels
		size_t k_s; // kernel_size
		size_t str; // stride
		size_t pad; // padding
		const double epsilon = 1 * pow(10, -7);
		double gamma = 1; // gamma value for batch normalization
		double beta = 0; // beta value for batch normalization

		void appendPadding(size_t pad);
		void appendTransposedPadding(size_t pad);

		friend void nn::saveAllWeights();
		friend void nn::loadAllWeights();

	public:

		Layer(size_t layer_id, nn& parent, size_t in_channels, size_t out_channels, size_t stride = 1, size_t padding = 0, size_t kernel_size = 4);
		void appendOutput() {
			l_outputs->operator[](layer_id) = *X; //NADO ZAMENIT L_OUTPUTS UBRAT UKAZATELI;
		};

		void printlayerid() { std::cout << "id: " << layer_id << std::endl; };
		void printX() { X->printTensorValues(); };

		void printKernelValues();
		void conv();
		void transposedConv();
		void actReLu();
		void actLeakyReLu(double sloat = 0.2);
		void actSigmoid();
		void actTanh();
		void batchNorm();

		void backConv();
		void backTransposeConv();
		void backBatchNorm();
	};

	std::vector<Layer*> layers;
};


struct DCGAN {

	class Discriminator : public nn
	{
	private:

		std::vector<double> batch_d_outputs;
		std::vector<double> d_outputs;

		void printOutputs()
		{
			for (size_t i = 0; i < d_outputs.size(); i++)
			{
				std::cout << i + 1 << " D(x) output: " << d_outputs[i] << std::endl;
				std::cout << i + 1 << " D(G(z)) output: " << d_outputs[i + 1] << std::endl;
				i++;
			}
		}
		void countBatchError() override
		{
			error = 0;
			double error_sum = 0;
			size_t n = batch_d_outputs.size();
			for (size_t i = 0; i <= n - 1; i++)
			{
				error_sum += log(batch_d_outputs[i]) + log(1 - batch_d_outputs[i + 1]); // to MAX
			}
			error = -(1.0 / batch_d_outputs.size()) * error_sum;
		}
		void countOuterGradient(size_t batch_i) override
		{
			// d / d(x) = -1 / D(x)
			//d / D(G(z)) = 1 / (1 - D(G(z))
			if (batch_i == 0)
			{
				for (size_t i = 0; i < X.getX(); i++) {
					for (size_t j = 0; j < X.getY(); j++) {
						for (size_t k = 0; k < X.getZ(); k++) {
							X.operator()(i, j, k) = -1 / d_outputs[0]; //for D(x) //64x64
						}
					}
				}
			}
			else
			{
				for (size_t i = 0; i < X.getX(); i++) {
					for (size_t j = 0; j < X.getY(); j++) {
						for (size_t k = 0; k < X.getZ(); k++) {
							X.operator()(i, j, k) = 1 / (1 - d_outputs[1]); //for D(G(z))
						}
					}
				}
			}


		};

	public:

		std::vector<double>& getOutputs() { return d_outputs; }
		std::vector<double>& getBatchOutputs() { return batch_d_outputs; }

		Discriminator(std::string nnName)
		{

			name = nnName;

			layers.resize(5);

			//	layer[0] = new Layer(*this, 3, 64, 2, 1), //64x64x3 --> 32x32x64
			//	layer[1] = new Layer(*this, 64, 128, 2, 1), //32x32x64 --> 16x16x128
			//	layer[2] = new Layer(*this, 128, 256, 2, 1), //16x16x128 --> 8x8x256
			//	layer[3] = new Layer(*this, 256, 512, 2, 1), //8x8x256 --> 4x4x512
			//	layer[4] = new Layer(*this, 512, 1) // 4x4x512 --> 1x1x1

			std::thread t1([&]() {
				layers[0] = new Layer(0, *this, 3, 64, 2, 1); //64x64x3 --> 32x32x64
				});

			std::thread t2([&]() {
				layers[1] = new Layer(1, *this, 64, 128, 2, 1); //32x32x64 --> 16x16x128
				});

			std::thread t3([&]() {
				layers[2] = new Layer(2, *this, 128, 256, 2, 1); //16x16x128 --> 8x8x256
				});

			std::thread t4([&]() {
				layers[3] = new Layer(3, *this, 256, 512, 2, 1); //8x8x256 --> 4x4x512
				});

			std::thread t5([&]() {
				layers[4] = new Layer(4, *this, 512, 1); // 4x4x512 --> 1x1x1
				});

			t1.join();
			t2.join();
			t3.join();
			t4.join();
			t5.join();
		}

		~Discriminator()
		{
			for (auto& layer : layers) {
				delete layer;
			}
			/*for (auto &l_output : l_outputs) {
				delete l_output;
			}*/
		}

		void forward(Tensor3d<double>& input) override
		{

			//input layer
			X = input;

			//Layer 1
			layers[0]->conv();
			layers[0]->actLeakyReLu();
			layers[0]->appendOutput();

			//Layer 2
			layers[1]->conv();
			layers[1]->batchNorm();
			layers[1]->actLeakyReLu();
			layers[1]->appendOutput();

			//Layer 3
			layers[2]->conv();
			layers[2]->batchNorm();
			layers[2]->actLeakyReLu();
			layers[2]->appendOutput();

			//Layer 4
			layers[3]->conv();
			layers[3]->batchNorm();
			layers[3]->actLeakyReLu();
			layers[3]->appendOutput();

			//Layer 5
			layers[4]->conv();
			layers[4]->actSigmoid();
			layers[4]->appendOutput();

			d_outputs.push_back(X(0, 0, 0));
			batch_d_outputs.push_back(X(0, 0, 0));
		}

		void backward() override
		{
			countOuterGradient(0);
			layers[4]->backConv();

			//d_outputs.clear(); sdelat otdelnij metod chtobi vse chistit
		}
	};

	class Generator : public nn
	{
	private:

		DCGAN::Discriminator* ptr_d = nullptr;

		void countBatchError() override
		{
			error = 0;
			double error_sum = 0;
			std::vector<double> outputs = ptr_d->getBatchOutputs();
			size_t n = outputs.size();
			for (size_t i = 0; i < n; i++)
			{
				//error_sum += log(1 - outputs[i]);  //to MIN
				if (i % 2 != 0 && i != 0) {
					error_sum += log(outputs[i]); //to MAX
				}
			}
			error = -(1.0 / (n / 2)) * error_sum; //SDES NADO LIBO MINUS LIBO PLUS SMOTRI
		}
		void countOuterGradient(size_t batch_i) override
		{
			//dx = -1/d(g(z))
			double outputs = ptr_d->getOutputs().operator[](1);
			for (size_t i = 0; i < X.getX(); i++) {
				for (size_t j = 0; j < X.getY(); j++) {
					for (size_t k = 0; k < X.getZ(); k++) {
						X.operator()(i, j, k) = -1 / outputs;
					}
				}
			}
		};

	public:

		void setPointerToDiscriminator(DCGAN::Discriminator& disc_link) { ptr_d = &disc_link; }

		//Layer glayers[5]
		//{
		//	Layer(X, 100, 512), //1x1x100 --> 4x4x512
		//	Layer(X, 512, 256, 2, 1), //4x4x512 --> 8x8x256
		//	Layer(X, 256, 128, 2, 1), //8x8x256 --> 16x16x128
		//	Layer(X, 128, 64, 2, 1), //16x16x128 --> 32x32x64
		//	Layer(X, 64, 3, 2, 1) // 32x32x64 --> 64x64x3
		//};

		Generator(std::string nnName)
		{
			name = nnName;
			layers.resize(5);

			//	layer[0] = new Layer(*this, 100, 512), //1x1x100 --> 4x4x512
			//	layer[1] = new Layer(*this, 512, 256, 2, 1), //4x4x512 --> 8x8x256
			//	layer[2] = new Layer(*this, 256, 128, 2, 1), //8x8x256 --> 16x16x128
			//	layer[3] = new Layer(*this, 128, 64, 2, 1), //16x16x128 --> 32x32x64
			//	layer[4] = new Layer(*this, 64, 3, 2, 1) // 32x32x64 --> 64x64x3

			std::thread t1([&]() {
				layers[0] = new Layer(0, *this, 100, 512); //1x1x100 --> 4x4x512
				});

			std::thread t2([&]() {
				layers[1] = new Layer(1, *this, 512, 256, 2, 1); //4x4x512 --> 8x8x256
				});

			std::thread t3([&]() {
				layers[2] = new Layer(2, *this, 256, 128, 2, 1); //8x8x256 --> 16x16x128
				});

			std::thread t4([&]() {
				layers[3] = new Layer(3, *this, 128, 64, 2, 1); //16x16x128 --> 32x32x64
				});

			std::thread t5([&]() {
				layers[4] = new Layer(4, *this, 64, 3, 2, 1); // 32x32x64 --> 64x64x3
				});

			t1.join();
			t2.join();
			t3.join();
			t4.join();
			t5.join();
		}

		~Generator()
		{
			for (auto& layer : layers) {
				delete layer;
			}
			/*for (auto& l_output : l_outputs) {
				delete l_output;
			}*/
		}

		void forward(Tensor3d<double>& input) override
		{

			//input layer
			X = input;

			//Layer 1
			layers[0]->transposedConv();
			layers[0]->batchNorm();
			layers[0]->actReLu();
			layers[0]->appendOutput();

			//Layer 2
			layers[1]->transposedConv();
			layers[1]->batchNorm();
			layers[1]->actReLu();
			layers[1]->appendOutput();

			//Layer 3
			layers[2]->transposedConv();
			layers[2]->batchNorm();
			layers[2]->actReLu();
			layers[2]->appendOutput();

			//Layer 4
			layers[3]->transposedConv();
			layers[3]->batchNorm();
			layers[3]->actReLu();
			layers[3]->appendOutput();

			//Layer 5
			layers[4]->transposedConv();
			layers[4]->actTanh();
			layers[4]->appendOutput();
		}

		void backward() override
		{
			countOuterGradient(0);
		}
	};
};

void totalLossFunction(DCGAN::Discriminator& name);
void saveAllWeights(DCGAN::Discriminator& dis, DCGAN::Generator& gen);
void loadAllWeights(DCGAN::Discriminator& dis, DCGAN::Generator& gen);

//Generator
//void countError() override
//{
//	double error_sum = 0;
//	std::vector<double> outputs = ptr_d->getOutputs();
//	size_t n = outputs.size() / 2;
//	for (size_t i = 1; i <= n; i += 2)
//	{
//		//error_sum += log(1 - outputs[i]);  //to MIN
//		error_sum += log(outputs[i]); //to MAX
//	}
//	error = -(1.0 / n) * error_sum; //SDES NADO LIBO MINUS LIBO PLUS SMOTRI
//}

//Discriminator
//void countError() override
//{
//	double error_sum = 0;
//	size_t n = outputs.size() / 2;
//	for (size_t i = 0; i < n; i++)
//	{
//		error_sum += log(outputs[i]) + log(1 - outputs[i + 1]); // to MAX
//		i++;
//	}
//	error = -(1.0 / n) * error_sum;
//}