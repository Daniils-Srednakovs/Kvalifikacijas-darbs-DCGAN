#include "neuralnetwork.h"

double NeuralNetwork::normalDistribution(double mju, double sigma)
{
	std::random_device rd;
	std::default_random_engine e(rd());
	std::normal_distribution<double> distN(mju, sigma);
	return distN(e);
}

void NeuralNetwork::nn::saveAllWeights()
{
	PWSTR getpath = NULL;
	SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &getpath);
	std::wstring wpath(getpath);
	std::wstring wname(name.begin(), name.end());
	std::wstring filename = wpath + L"\\DCGAN\\weights\\" + wname + L".csv";

	std::ofstream main_out;

	main_out.open(filename, std::ofstream::app);
	if (!main_out.is_open())
	{
		throw std::exception("Error: fail ne otrit!\n");
	}
	else
	{
		for (size_t li = 0; li < layers.size(); li++)
		{
			main_out << typeid(*this).name() << " Layer " << li << '\n';

			for (size_t i = 0; i < layers[li]->V.getX(); i++) {
				for (size_t j = 0; j < layers[li]->V.getY(); j++) {
					for (size_t k = 0; k < layers[li]->V.getZ(); k++) {
						for (size_t l = 0; l < layers[li]->V.getD(); l++) {
							main_out << layers[li]->V(i, j, k, l) << ';';
						}
						main_out << '\n';
					}
				}
			}
		}
	}
	main_out.close();
}

void NeuralNetwork::nn::loadAllWeights()
{
	PWSTR getpath = NULL;
	SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &getpath);
	std::wstring wpath(getpath);
	std::wstring wname(name.begin(), name.end());
	std::wstring filename = wpath + L"\\DCGAN\\weights\\" + wname + L".csv";

	std::ifstream read_main(filename);

	if (!read_main.is_open())
	{
		throw std::exception("Error: fail ne otrit!\n");
	}
	else
	{
		std::vector<std::thread> threads;
		std::function<void(unsigned int li)> func = [&](unsigned int li)
		{
			std::ifstream read_second(filename);

			std::string id_li = (std::string)typeid(*this).name() + " Layer " + std::to_string(li);

			std::string line;

			for (int curLine = 0; std::getline(read_second, line); curLine++) {
				if (line.find(id_li) != std::string::npos)
				{
					//std::cout << "found: " << id_li << " line: " << curLine << std::endl;

					for (size_t i = 0; i < layers[li]->V.getX(); i++) {
						for (size_t j = 0; j < layers[li]->V.getY(); j++) {
							for (size_t k = 0; k < layers[li]->V.getZ(); k++) {
								for (size_t l = 0; l < layers[li]->V.getD(); l++)
								{
									char ch;
									std::string double_str = "";
									while (read_second.get(ch)) {
										if (ch == ';') {
											break;
										}
										double_str += ch;
									}
									//std::cout << double_str<<std::endl;
									layers[li]->V(i, j, k, l) = std::stod(double_str);
								}
							}
						}
					}
					break;
				}
			}
			read_second.close();
		};

		for (unsigned int li = 0; li < layers.size(); li++) {
			threads.push_back(std::thread(func, li));
		}

		for (std::thread& th : threads)
		{
			if (th.joinable())
				th.join();
		}
	}
	read_main.close();
}

void NeuralNetwork::nn::Layer::appendPadding(size_t pad)
{
	Tensor3d<double> nX(X->getX() + pad * 2, X->getY() + pad * 2, X->getZ());
	nX.fill();

	for (size_t i = pad; i < X->getX() + pad; i++) {
		for (size_t j = pad; j < X->getY() + pad; j++) {
			for (size_t k = 0; k < nX.getZ(); k++)
			{
				nX(i, j, k) = X->operator()(i - pad, j - pad, k);
			}
		}
	}

	X->operator=(nX);
}

void NeuralNetwork::nn::Layer::appendTransposedPadding(size_t pad)
{
	Tensor3d<double> nX(X->getX() - pad * 2, X->getY() - pad * 2, X->getZ());

	for (size_t i = 0; i < nX.getX(); i++) {
		for (size_t j = 0; j < nX.getY(); j++) {
			for (size_t k = 0; k < nX.getZ(); k++)
			{
				nX(i, j, k) = X->operator()(i + pad, j + pad, k);
			}
		}
	}

	X->operator=(nX);
}

NeuralNetwork::nn::Layer::Layer(size_t layer_id, nn& parent, size_t in_channels, size_t out_channels, size_t stride, size_t padding, size_t kernel_size)
{
	//naznachenie peremennih
	this->layer_id = layer_id;
	parent.l_outputs.push_back(Tensor3d<double>());
	l_outputs = &parent.l_outputs;
	X_input_memory = &parent.X_input_memory;
	X = &parent.X;

	nbatch = parent.nbatch;
	double deviation = parent.deviation;
	learning_rate = parent.learning_rate;
	m_beta1 = parent.momentumb1;

	i_ch = in_channels;
	o_ch = out_channels;
	k_s = kernel_size;
	str = stride;
	pad = padding;

	//bacthnorm

	//inizializatsija vesov
	Tensor4d<double> nV(k_s, k_s, i_ch, o_ch); //new V
	for (size_t i = 0; i < k_s; i++) {
		for (size_t j = 0; j < k_s; j++) {
			for (size_t k = 0; k < i_ch; k++) {
				for (size_t l = 0; l < o_ch; l++)
				{
					nV(i, j, k, l) = normalDistribution(0, 0.02);
				}
			}
		}
	}
	V = nV;

	sum_gradient_V = nV;
	sum_gradient_V.fill();
	//momentum1_m = nV;
	//momentum2_v = nV;
	prev_momentum1_m = nV;
	prev_momentum1_m.fill();
	prev_momentum2_v = nV;
	prev_momentum2_v.fill();
}

void NeuralNetwork::nn::Layer::printKernelValues()
{
	V.printTensorValues();
}

void NeuralNetwork::nn::Layer::conv()
{
	size_t nh = (X->getX() - k_s + pad * 2 + str) / str;
	size_t nw = (X->getY() - k_s + pad * 2 + str) / str;

	if (pad != 0)
	{
		X->appendPadding(pad);
	}

	Tensor3d<double> nX(nh, nw, o_ch);
	nX.fill();

	for (size_t i = 0; i < nh; i++) {
		for (size_t j = 0; j < nw; j++) {
			for (size_t d = 0; d < o_ch; d++) {

				double sum = 0;
				for (size_t a = 0; a < k_s; a++) {
					for (size_t b = 0; b < k_s; b++) {
						for (size_t c = 0; c < i_ch; c++)
						{
							sum += V(a, b, c, d) * X->operator()(i * str + a, j * str + b, c);
						}
					}
				}
				nX(i, j, d) = sum;
				//std::cout << nX(i, j, d) << std::endl;
			}
		}
	}

	X->operator=(nX);
}

void NeuralNetwork::nn::Layer::transposedConv()
{
	//hight and width for output tensor
	size_t nh = (X->getX() - 1) * str + k_s - 2 * pad;
	size_t nw = (X->getY() - 1) * str + k_s - 2 * pad;

	//hight and width for output tensor before padding
	nh += 2 * pad;
	nw += 2 * pad;

	Tensor3d<double> nX(nh, nw, o_ch);
	nX.fill();

	for (size_t i = 0; i < X->getY(); i++) {
		for (size_t j = 0; j < X->getX(); j++) {
			for (size_t c = 0; c < X->getZ(); c++) {

				for (size_t a = 0; a < k_s; a++) {
					for (size_t b = 0; b < k_s; b++) {
						for (size_t d = 0; d < o_ch; d++) {
							nX(i * str + a, j * str + b, d) += X->operator()(i, j, c) * V(a, b, c, d);
						}
					}
				}
			}
		}
	}

	X->operator=(nX);

	if (pad != 0)
	{
		X->appendTransposedPadding(pad);
	}
}

void NeuralNetwork::nn::Layer::actReLu()
{
	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t d = 0; d < X->getZ(); d++)
			{
				if (X->operator()(i, j, d) < 0)
				{
					X->operator()(i, j, d) = 0;
				}
			}
		}
	}
}

void NeuralNetwork::nn::Layer::actLeakyReLu(double sloat)
{
	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t d = 0; d < X->getZ(); d++)
			{
				if (X->operator()(i, j, d) < 0)
				{
					X->operator()(i, j, d) *= sloat;
				}
			}
		}
	}
}

void NeuralNetwork::nn::Layer::actSigmoid()
{
	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t d = 0; d < X->getZ(); d++)
			{
				X->operator()(i, j, d) = 1 / (1 + exp(-(X->operator()(i, j, d))));
			}
		}
	}
}

void NeuralNetwork::nn::Layer::actTanh()
{
	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t d = 0; d < X->getZ(); d++)
			{
				double x = X->operator()(i, j, d);
				X->operator()(i, j, d) = (exp(x) - exp(-x)) / (exp(x) + exp(-x));
			}
		}
	}
}

void NeuralNetwork::nn::Layer::batchNorm()
{
	size_t batch = o_ch;
	output_inter_x = Tensor3d<double>(X->getX(), X->getY(), o_ch);
	input_x_in_batch = Tensor3d<double>(X->getX(), X->getY(), o_ch);

	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++)
		{
			//dla backpropagation input sohranaju
			for (size_t k = 0; k < batch; k++)
			{
				input_x_in_batch(i, j, k) = X->operator()(i, j, k);
			}

			//batchnormalization

			double sum_b = 0;
			for (size_t k = 0; k < batch; k++)
			{
				sum_b += X->operator()(i, j, k);
			}
			double mju_b = (1.0 / batch) * sum_b;
			output_mju_b = mju_b;

			sum_b = 0;
			for (size_t k = 0; k < batch; k++)
			{
				sum_b += pow(X->operator()(i, j, k) - mju_b, 2);
			}

			double sigma_b = (1.0 / batch) * sum_b;
			output_sigma_b = sigma_b;

			for (size_t k = 0; k < batch; k++)
			{
				double inter_x = (X->operator()(i, j, k) - mju_b) / (sqrt(sigma_b + epsilon));
				output_inter_x(i, j, k) = inter_x;

				X->operator()(i, j, k) = gamma * inter_x + beta;

			}
		}
	}
}

void NeuralNetwork::totalLossFunction(Discriminator& name) {
	double error_sum = 0;
	std::vector<double> outputs = name.getOutputs();
	size_t n = outputs.size() / 2;
	for (size_t i = 0; i < n; i++)
	{
		error_sum += log(outputs[i]) + log(1 - outputs[i + 1]) + log(outputs[i + 1]);  //to MIN
		i++;
	}
	double error = -(1.0 / n) * error_sum;

	std::cout << "T error: " << error << std::endl;
}

void NeuralNetwork::saveAllWeights(Discriminator& dis, Generator& gen)
{
	std::string filename = "weights/" + dis.getName() + ".csv";

	std::ofstream main_out;
	main_out.open(filename, std::ofstream::trunc);
	if (!main_out.is_open())
	{
		throw std::exception("Error: fail ne otrit!\n");
	}
	else
	{
		main_out.close();
		dis.saveAllWeights();
		gen.saveAllWeights();
	}
	main_out.close();
}

void NeuralNetwork::loadAllWeights(Discriminator& dis, Generator& gen)
{
	std::thread t1([&]() {
		dis.loadAllWeights();
		});
	std::thread t2([&]() {
		gen.loadAllWeights();
		});
	t1.join();
	t2.join();
}

void NeuralNetwork::nn::Layer::backConv()
{
	Tensor4d<double> nK(k_s, k_s, i_ch, o_ch); //new kernek gradient
	nK.fill();

	Tensor3d<double> il;
	if ((int)layer_id - 1 == -1) {
		//undefined bug when using | il = *X_input_memory
		size_t xX = X_input_memory->getX();
		size_t xY = X_input_memory->getY();
		size_t xZ = X_input_memory->getZ();
		il = Tensor3d<double>(xX, xY, xZ);
		for (size_t i = 0; i < xX; i++) {
			for (size_t j = 0; j < xY; j++) {
				for (size_t k = 0; k < xZ; k++) {
					il(i, j, k) = X_input_memory->operator()(i, j, k);
				}
			}
		}
	}
	else
	{
		il = l_outputs->operator[](layer_id - 1); //X or input from past layer
	}

	Tensor3d<double> oZ(X->getX(), X->getY(), X->getZ()); //input gradient //tut bug esli oZ = *X
	for (size_t i = 0; i < oZ.getX(); i++) {
		for (size_t j = 0; j < oZ.getY(); j++) {
			for (size_t k = 0; k < oZ.getZ(); k++) {
				oZ(i, j, k) = X->operator()(i, j, k);
			}
		}
	}

	if (pad != 0)
	{
		il.appendPadding(pad);
		oZ.interweave();
	}

	//gradient kernel

	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t d = 0; d < o_ch; d++) {

				//double sum = 0;
				for (size_t a = 0; a < k_s; a++) {
					for (size_t b = 0; b < k_s; b++) {
						for (size_t c = 0; c < i_ch; c++)
						{
							nK(a, b, c, d) += oZ(i, j, d) * il(i + a, j + b, c); //i * str + a, j * str + b, c
						}
					}
				}
			}
		}
	}

	for (size_t a = 0; a < nK.getX(); a++) {
		for (size_t b = 0; b < nK.getY(); b++) {
			for (size_t c = 0; c < nK.getZ(); c++) {
				for (size_t d = 0; d < nK.getD(); d++)
				{
					sum_gradient_V(a, b, c, d) += nK(a, b, c, d);
				}
			}
		}
	}

	//sum_gradient_V.printTensorValues();
	//std::cout << "===============" << std::endl;

	//gradient vhodnih znachenij
	size_t nh = 0;
	size_t nw = 0;
	size_t nc = 0;
	if ((int)layer_id - 1 == -1) {
		return; //end of function
	}
	else {
		nh = l_outputs->operator[](layer_id - 1).getX();
		nw = l_outputs->operator[](layer_id - 1).getY();
		nc = l_outputs->operator[](layer_id - 1).getZ();
	}
	Tensor3d<double> nil(nh, nw, nc);
	nil.fill();
	nK = V;
	nK.rotate180();

	//sdes provoditsa ne obicnnaja svertka a full convolution, poetomu pustie mesta nado zapolnit

	size_t padding = 1;
	while (true) {
		size_t h = (X->getX() - k_s + padding * 2 + 1) / 1;
		if (h < nh) {
			padding++;
		}
		else if (h >= nh) {
			break;
		}
	}
	oZ.appendPadding(padding);

	for (size_t i = 0; i < nh; i++) {
		for (size_t j = 0; j < nw; j++) {
			for (size_t d = 0; d < nc; d++) { //o_ch

				double sum = 0;
				for (size_t a = 0; a < k_s; a++) {
					for (size_t b = 0; b < k_s; b++) {
						for (size_t c = 0; c < o_ch; c++) //i_ch
						{
							//nil(i + a, j + b, c) += nK(a, b, c, d) * oZ(i, j, d);
							sum += nK(a, b, d, c) * oZ(i + a, j + b, c);
						}
					}
				}
				nil(i, j, d) = sum;
			}
		}
	}
	X->operator=(nil);
	//X->printTensorValues();
}

void NeuralNetwork::nn::Layer::backTransposedConv()
{
}

void NeuralNetwork::nn::Layer::backBatchNorm()
{
	size_t batch = X->getZ();
	double gradient_beta = 0;
	double gradient_gamma = 0;
	Tensor3d<double> gradient_inter_x(X->getX(), X->getY(), X->getZ());
	double gradient_sigma_b = 0;
	double gradient_mju_b = 0;

	//delta beta viccheslenie
	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t k = 0; k < X->getZ(); k++) {
				gradient_beta += X->operator()(i, j, k);
				gradient_gamma += (X->operator()(i, j, k) * output_inter_x(i, j, k));
				gradient_inter_x(i, j, k) = (X->operator()(i, j, k) * gamma);
				gradient_sigma_b += ((gradient_inter_x(i, j, k) * (input_x_in_batch(i, j, k) - output_mju_b)) * (-1 / 2) * pow(output_sigma_b + epsilon, -3 / 2));
			}
		}
	}

	//gradient mju b
	double temp1 = 0;
	double temp2 = 0;

	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t k = 0; k < X->getZ(); k++) {
				temp1 += gradient_inter_x(i, j, k) * (-1 / sqrt(output_sigma_b + epsilon));
				temp2 += -2 * (input_x_in_batch(i, j, k) - output_mju_b);
			}
		}
	}

	gradient_mju_b = temp1 + gradient_sigma_b * (temp2 / batch);

	//gradient input
	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t k = 0; k < X->getZ(); k++) {
				X->operator()(i, j, k) = gradient_inter_x(i, j, k) * (1 / sqrt(output_sigma_b + epsilon)) + gradient_sigma_b * ((2 * (input_x_in_batch(i, j, k) - output_mju_b)) / batch) + gradient_mju_b * (1 / batch);
			}
		}
	}

	sum_gradient_gamma += gradient_gamma;
	sum_gradient_beta += gradient_beta;
}

void NeuralNetwork::nn::Layer::updateParameters()
{
	//weights
	w_timestep++;

	Tensor4d<double> gradient_V(k_s, k_s, i_ch, o_ch);
	Tensor4d<double> momentum1_m(k_s, k_s, i_ch, o_ch);
	Tensor4d<double> momentum2_v(k_s, k_s, i_ch, o_ch);
	Tensor4d<double> corrected_momentum1_m(k_s, k_s, i_ch, o_ch);
	Tensor4d<double> corrected_momentum2_v(k_s, k_s, i_ch, o_ch);

	for (size_t i = 0; i < k_s; i++) {
		for (size_t j = 0; j < k_s; j++) {
			for (size_t k = 0; k < i_ch; k++) {
				for (size_t l = 0; l < o_ch; l++)
				{
					//vichislenie gradienta vesov
					gradient_V(i, j, k, l) = sum_gradient_V(i, j, k, l) / nbatch;
					momentum1_m(i, j, k, l) = m_beta1 * prev_momentum1_m(i, j, k, l) + (1 - m_beta1) * gradient_V(i, j, k, l);
					momentum2_v(i, j, k, l) = m_beta2 * prev_momentum2_v(i, j, k, l) + (1 - m_beta2) * pow(gradient_V(i, j, k, l), 2);
					corrected_momentum1_m(i, j, k, l) = momentum1_m(i, j, k, l) / (1 - pow(m_beta1, w_timestep));
					corrected_momentum2_v(i, j, k, l) = momentum2_v(i, j, k, l) / (1 - pow(m_beta2, w_timestep));
					//V(i, j, k, l) = V(i, j, k, l) - (learning_rate / (sqrt(corrected_momentum2_v(i, j, k, l)) + epsilon)) * corrected_momentum1_m(i, j, k, l);
					V(i, j, k, l) = V(i, j, k, l) - learning_rate * (corrected_momentum1_m(i, j, k, l) / (sqrt(corrected_momentum2_v(i, j, k, l)) + epsilon));
					//sohr parametrov
					prev_momentum1_m(i, j, k, l) = momentum1_m(i, j, k, l);
					prev_momentum2_v(i, j, k, l) = momentum2_v(i, j, k, l);
				}
			}
		}
	}

	//batch normalization
	bn_timestep++;
	double gradient_beta = sum_gradient_beta / nbatch;
	double gradient_gamma = sum_gradient_gamma / nbatch;

	//update beta
	double batchn_beta_momentum1_m = m_beta1 * batchn_beta_prev_momentum1_m + (1 - m_beta1) * gradient_beta;
	double batchn_beta_momentum2_v = m_beta2 * batchn_beta_prev_momentum2_v + (1 - m_beta2) * pow(gradient_beta, 2);
	double corrected_batchn_beta_momentum1_m = batchn_beta_momentum1_m / (1 - pow(m_beta1, bn_timestep));
	double corrected_batchn_beta_momentum2_v = batchn_beta_momentum2_v / (1 - pow(m_beta2, bn_timestep));
	//beta = beta - (learning_rate / (sqrt(corrected_batchn_beta_momentum2_v) + epsilon)) * corrected_batchn_beta_momentum1_m;
	beta = beta - learning_rate * (corrected_batchn_beta_momentum1_m / (sqrt(corrected_batchn_beta_momentum2_v) + epsilon));

	//update gamma
	double batchn_gamma_momentum1_m = m_beta1 * batchn_gamma_prev_momentum1_m + (1 - m_beta1) * gradient_gamma;
	double batchn_gamma_momentum2_v = m_beta2 * batchn_gamma_prev_momentum2_v + (1 - m_beta2) * pow(gradient_gamma, 2);
	double corrected_batchn_gamma_momentum1_m = batchn_gamma_momentum1_m / (1 - pow(m_beta1, bn_timestep));
	double corrected_batchn_gamma_momentum2_v = batchn_gamma_momentum2_v / (1 - pow(m_beta2, bn_timestep));
	//gamma = gamma - (learning_rate / (sqrt(corrected_batchn_gamma_momentum2_v) + epsilon)) * corrected_batchn_gamma_momentum1_m;
	gamma = gamma - learning_rate * (corrected_batchn_gamma_momentum1_m / (sqrt(corrected_batchn_gamma_momentum2_v) + epsilon));

	//sohr parametrov
	batchn_beta_prev_momentum1_m = batchn_beta_momentum1_m;
	batchn_beta_prev_momentum2_v = batchn_beta_momentum2_v;
	batchn_gamma_prev_momentum1_m = batchn_gamma_momentum1_m;
	batchn_gamma_prev_momentum2_v = batchn_gamma_momentum2_v;

	//obnulenie parametrov
	sum_gradient_V.fill();
	sum_gradient_beta = 0;
	sum_gradient_gamma = 0;

}

void NeuralNetwork::nn::updateAllParameters() {
	for (size_t i = 0; i < layers.size(); i++) {
		layers[i]->updateParameters();
	}
}