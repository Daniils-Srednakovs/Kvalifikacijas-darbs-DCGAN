#pragma once
#include <iostream>
#include <random>
#include <thread>
#include <fstream>
#include <functional>
#include <string>
#include <shlobj.h>
#include <msclr\marshal_cppstd.h>
#include <math.h>

#pragma comment(lib, "shell32.lib")


#include "tensor.h"
#include "imagerw.h"

namespace NeuralNetwork {

	double normalDistribution(double mju = 0, double sigma = 1);

	class nn
	{
	public:

		void printNeurons() { X.printTensorValues(); }
		Tensor3d<double>& getNeurons() { return X; }
		std::string getName() { return name; }
		void saveAllWeights();
		void loadAllWeights();
		void updateAllParameters();
		void printKernels(size_t i) {
			layers[i - 1]->printKernelValues();
		}
		double getError() { return error; };

		void printids() { for (auto layerr : layers) { layerr->printlayerid(); } };

	protected:

		std::string name = "";
		size_t nbatch = 0;
		double learning_rate = 0;
		double momentumb1 = 0;
		double deviation = 0;

		Tensor3d<double> X;
		std::vector<Tensor3d<double>> l_outputs;
		Tensor3d<double> X_input_memory; //save input to nn for backpropagation

		double error = 0;

		virtual void countBatchError() = 0;
		virtual void forward(Tensor3d<double>& input) = 0;
		virtual void backward() = 0;
		virtual void countOuterGradient(size_t entry_type) = 0;

		class Layer
		{
		private:
			size_t layer_id;
			size_t nbatch;
			std::vector<Tensor3d<double>>* l_outputs; //pointer to parent l_outputs
			Tensor3d<double>* X_input_memory; //pointer to parent x_input
			Tensor3d<double>* X;
			Tensor4d<double> V;
			Tensor4d<double> sum_gradient_V;
			size_t i_ch; // in_channels
			size_t o_ch; // out_channels
			size_t k_s; // kernel_size
			size_t str; // stride
			size_t pad; // padding

			//parametri
			const double epsilon = 1 * pow(10, -8);

			//batch norm
			double gamma = 1; // gamma value for batch normalization
			double beta = 0; // beta value for batch normalization
			Tensor3d<double> output_inter_x; //inter x dla backpropagation
			Tensor3d<double> input_x_in_batch;
			double output_sigma_b;
			double output_mju_b;
			double sum_gradient_gamma = 0;
			double sum_gradient_beta = 0;

			//adam optimizer
			size_t w_timestep = 0; //timestep for weights
			double m_beta1 = 0.5; //adam momentum 1
			const double m_beta2 = 0.999; ////adam momentum 2
			double learning_rate = 0.0002; //learning rate
			Tensor4d<double> prev_momentum1_m;
			Tensor4d<double> prev_momentum2_v;

			//adam for batchnorm
			//const double batchn_m_beta1 = 0.9;
			size_t bn_timestep = 0; //timestep for batch norm
			//gamma
			double batchn_gamma_prev_momentum1_m = 0;
			double batchn_gamma_prev_momentum2_v = 0;
			//beta
			double batchn_beta_prev_momentum1_m = 0;
			double batchn_beta_prev_momentum2_v = 0;


			void appendPadding(size_t pad);
			void appendTransposedPadding(size_t pad);

			friend void nn::saveAllWeights();
			friend void nn::loadAllWeights();

		public:

			Layer(size_t layer_id, nn& parent, size_t in_channels, size_t out_channels, size_t stride = 1, size_t padding = 0, size_t kernel_size = 4);
			void appendOutput() {
				l_outputs->operator[](layer_id) = *X;
			};

			void printlayerid() { std::cout << "id: " << layer_id << std::endl; };
			void printX() { X->printTensorValues(); };
			void printSumdv() { sum_gradient_V.printTensorValues(); };
			void printGradientBeta() { std::cout << "DBeta: " << sum_gradient_beta << std::endl; };
			void printGradientGamma() { std::cout << "DGamma: " << sum_gradient_gamma << std::endl; };

			void printKernelValues();
			void conv();
			void transposedConv();
			void actReLu();
			void actLeakyReLu(double sloat = 0.2);
			void actSigmoid();
			void actTanh();
			void batchNorm();
			void backConv();
			void backTransposedConv();
			void backBatchNorm();
			void updateParameters();
		};

		std::vector<Layer*> layers;
	};

	class Discriminator : public nn
	{
	private:

		std::vector<double> batch_d_outputs;
		std::vector<double> d_outputs;

		void countOuterGradient(size_t entry_type) override //0 - D(x),  1 - D(G(z)) 
		{
			// d / d(x) = -1 / D(x)
			//d / D(G(z)) = 1 / (1 - D(G(z))
			if (entry_type == 0)
			{
				for (size_t i = 0; i < X.getX(); i++) {
					for (size_t j = 0; j < X.getY(); j++) {
						for (size_t k = 0; k < X.getZ(); k++) {
							X.operator()(i, j, k) = -1.0 / d_outputs[0]; //for D(x) //64x64
						}
					}
				}
			}
			else if (entry_type == 1)
			{
				for (size_t i = 0; i < X.getX(); i++) {
					for (size_t j = 0; j < X.getY(); j++) {
						for (size_t k = 0; k < X.getZ(); k++) {
							X.operator()(i, j, k) = 1.0 / (1.0 - d_outputs[1]); //for D(G(z))
						}
					}
				}
			}


		};

	public:

		std::vector<double>& getOutputs() { return d_outputs; }
		std::vector<double>& getBatchOutputs() { return batch_d_outputs; }

		Discriminator(std::string nnName, size_t iBatch, double iLearning_rate, double iMomentum, double iDeviation)
		{

			name = nnName;
			nbatch = iBatch;
			learning_rate = iLearning_rate;
			deviation = iDeviation;
			momentumb1 = iMomentum;

			layers.resize(5);

			layers[0] = new Layer(0, *this, 3, 64, 2, 1); //64x64x3 --> 32x32x64
			layers[1] = new Layer(1, *this, 64, 128, 2, 1); //32x32x64 --> 16x16x128
			layers[2] = new Layer(2, *this, 128, 256, 2, 1); //16x16x128 --> 8x8x256
			layers[3] = new Layer(3, *this, 256, 512, 2, 1); //8x8x256 --> 4x4x512
			layers[4] = new Layer(4, *this, 512, 1); // 4x4x512 --> 1x1x1

			//std::thread d1([&]() {
			//	layers[0] = new Layer(0, *this, 3, 64, 2, 1); //64x64x3 --> 32x32x64
			//	});

			//std::thread d2([&]() {
			//	layers[1] = new Layer(1, *this, 64, 128, 2, 1); //32x32x64 --> 16x16x128
			//	});

			//std::thread d3([&]() {
			//	layers[2] = new Layer(2, *this, 128, 256, 2, 1); //16x16x128 --> 8x8x256
			//	});

			//std::thread d4([&]() {
			//	layers[3] = new Layer(3, *this, 256, 512, 2, 1); //8x8x256 --> 4x4x512
			//	});

			//std::thread d5([&]() {
			//	layers[4] = new Layer(4, *this, 512, 1); // 4x4x512 --> 1x1x1
			//	});

			//d1.join();
			//d2.join();
			//d3.join();
			//d4.join();
			//d5.join();
		}

		~Discriminator()
		{
			for (auto& layer : layers)
			{
				delete layer;
			}
		}

		void forward(Tensor3d<double>& input) override
		{

			//input layer
			X = input;
			X_input_memory = input;

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

			d_outputs.push_back(X.operator()(0, 0, 0));
			batch_d_outputs.push_back(X.operator()(0, 0, 0));
		}

		void backward() override
		{
			//Layer 5
			countOuterGradient(d_outputs.size() - 1);
			layers[4]->actSigmoid();
			layers[4]->backConv();

			//Layer 4
			layers[3]->actLeakyReLu();
			layers[3]->backBatchNorm();
			layers[3]->backConv();

			//Layer 3
			layers[2]->actLeakyReLu();
			layers[2]->backBatchNorm();
			layers[2]->backConv();

			//Layer 2
			layers[1]->actLeakyReLu();
			layers[1]->backBatchNorm();
			layers[1]->backConv();

			//Layer 1
			layers[0]->actLeakyReLu();
			layers[0]->backConv();
		}

		void clearOutputs() {
			d_outputs.clear();
		}

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
			for (size_t i = 1; i <= n / 2; i++)
			{
				error_sum += log(batch_d_outputs[i - 1]) + log(1 - batch_d_outputs[i]); // to MAX
			}
			error = -(1.0 / (double)batch_d_outputs.size()) * error_sum;
			//batch_d_outputs.clear();
		}
	};

	class Generator : public nn
	{
	private:

		Discriminator* ptr_d = nullptr;

		void countOuterGradient(size_t entry_type = NULL) override
		{
			//dx = -1/d(g(z))
			double outputs = ptr_d->getOutputs().operator[](1);
			for (size_t i = 0; i < X.getX(); i++) {
				for (size_t j = 0; j < X.getY(); j++) {
					for (size_t k = 0; k < X.getZ(); k++) {
						X.operator()(i, j, k) = 1.0 / outputs; //sdes bilo -1/ outputs
					}
				}
			}
		};

	public:

		void setPointerToDiscriminator(Discriminator& disc_link) { ptr_d = &disc_link; }

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
			error = (1.0 / ((double)n / 2.0)) * error_sum; //SDES NADO LIBO MINUS LIBO PLUS
			//ptr_d->getBatchOutputs().clear();
		}
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

			layers[0] = new Layer(0, *this, 100, 512); //1x1x100 --> 4x4x512
			layers[1] = new Layer(1, *this, 512, 256, 2, 1); //4x4x512 --> 8x8x256
			layers[2] = new Layer(2, *this, 256, 128, 2, 1); //8x8x256 --> 16x16x128
			layers[3] = new Layer(3, *this, 128, 64, 2, 1); //16x16x128 --> 32x32x64
			layers[4] = new Layer(4, *this, 64, 3, 2, 1); // 32x32x64 --> 64x64x3

			//Razbienie na potoki, ne rabotaet c++/cli

			//std::thread g1([&]() {
			//	layers[0] = new Layer(0, *this, 100, 512); //1x1x100 --> 4x4x512
			//	});

			//std::thread g2([&]() {
			//	layers[1] = new Layer(1, *this, 512, 256, 2, 1); //4x4x512 --> 8x8x256
			//	});

			//std::thread g3([&]() {
			//	layers[2] = new Layer(2, *this, 256, 128, 2, 1); //8x8x256 --> 16x16x128
			//	});

			//std::thread g4([&]() {
			//	layers[3] = new Layer(3, *this, 128, 64, 2, 1); //16x16x128 --> 32x32x64
			//	});

			//std::thread g5([&]() {
			//	layers[4] = new Layer(4, *this, 64, 3, 2, 1); // 32x32x64 --> 64x64x3
			//	});

			//g1.join();
			//g2.join();
			//g3.join();
			//g4.join();
			//g5.join();
		}

		Generator(std::string nnName, size_t iBatch, double iLearning_rate, double iMomentum, double iDeviation)
		{
			name = nnName;
			nbatch = iBatch;
			learning_rate = iLearning_rate;
			deviation = iDeviation;
			momentumb1 = iMomentum;

			layers.resize(5);

			std::thread g1([&]() {
				layers[0] = new Layer(0, *this, 100, 512); //1x1x100 --> 4x4x512
				});

			std::thread g2([&]() {
				layers[1] = new Layer(1, *this, 512, 256, 2, 1); //4x4x512 --> 8x8x256
				});

			std::thread g3([&]() {
				layers[2] = new Layer(2, *this, 256, 128, 2, 1); //8x8x256 --> 16x16x128
				});

			std::thread g4([&]() {
				layers[3] = new Layer(3, *this, 128, 64, 2, 1); //16x16x128 --> 32x32x64
				});

			std::thread g5([&]() {
				layers[4] = new Layer(4, *this, 64, 3, 2, 1); // 32x32x64 --> 64x64x3
				});

			g1.join();
			g2.join();
			g3.join();
			g4.join();
			g5.join();
		}

		~Generator()
		{
			for (auto& layer : layers) {
				delete layer;
			}
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
			countOuterGradient();

			//Layer 5
			layers[4]->actTanh();
			layers[4]->backTransposedConv();

			//Layer 4
			layers[3]->actReLu();
			layers[3]->backBatchNorm();
			layers[3]->backTransposedConv();

			//Layer 3
			layers[2]->actReLu();
			layers[2]->backBatchNorm();
			layers[2]->backTransposedConv();

			//Layer 2
			layers[1]->actReLu();
			layers[1]->backBatchNorm();
			layers[1]->backTransposedConv();

			layers[0]->actReLu();
			layers[0]->backBatchNorm();
			layers[0]->backTransposedConv();
		}
	};

	void totalLossFunction(Discriminator& name);
	void saveAllWeights(Discriminator& dis, Generator& gen);
	void loadAllWeights(Discriminator& dis, Generator& gen);
}