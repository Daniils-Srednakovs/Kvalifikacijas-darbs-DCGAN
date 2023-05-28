#include "neuralnetwork.h"

double normalDistribution(double mju, double sigma)
{
	std::random_device rd;
	std::default_random_engine e(rd());
	std::normal_distribution<double> distN(mju, sigma);
	return distN(e);
}

void nn::saveAllWeights()
{
	std::string filename = "weights/" + name + ".csv";

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

	//gotoline, getline, <<, ignore
}

void nn::loadAllWeights()
{
	std::string filename = "weights/" + name + ".csv";

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

void nn::Layer::appendPadding(size_t pad)
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

void nn::Layer::appendTransposedPadding(size_t pad)
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

nn::Layer::Layer(size_t layer_id, nn& parent, size_t in_channels, size_t out_channels, size_t stride, size_t padding, size_t kernel_size)
{
	//naznachenie peremennih
	this->layer_id = layer_id;
	//parent.l_outputs.resize(parent.l_outputs.size() + 1);
	parent.l_outputs.push_back(Tensor3d<double>());
	l_outputs = &parent.l_outputs;
	X = &parent.X;
	i_ch = in_channels;
	o_ch = out_channels;
	k_s = kernel_size;
	str = stride;
	pad = padding;

	//inizializatsija vesov
	Tensor4d<double> nV(k_s, k_s, i_ch, o_ch); //new V
	//sum_dV = nV;
	//sum_dV.fill();
	//dV = nV;
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
}

void nn::Layer::printKernelValues()
{
	V.printTensorValues();
}

void nn::Layer::conv()
{
	size_t nh = (X->getX() - k_s + pad * 2 + str) / str;
	size_t nw = (X->getY() - k_s + pad * 2 + str) / str;

	if (pad != 0)
	{
		appendPadding(pad);
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

void nn::Layer::transposedConv()
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
		appendTransposedPadding(pad);
	}
}

void nn::Layer::actReLu()
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

void nn::Layer::actLeakyReLu(double sloat)
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

void nn::Layer::actSigmoid()
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

void nn::Layer::actTanh()
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

void nn::Layer::batchNorm()
{
	size_t batch = o_ch; //tebe nado eto zamenit po haroshemu
	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++)
		{
			double sum_b = 0;
			for (size_t k = 0; k < batch; k++)
			{
				sum_b += X->operator()(i, j, k);
			}
			double mju_b = (1.0 / batch) * sum_b;

			sum_b = 0;
			for (size_t k = 0; k < batch; k++)
			{
				sum_b += pow(X->operator()(i, j, k) - mju_b, 2);
			}

			double sigma_b = (1.0 / batch) * sum_b;

			for (size_t k = 0; k < batch; k++)
			{
				X->operator()(i, j, k) = gamma * ((X->operator()(i, j, k) - mju_b) / (sqrt(sigma_b + epsilon))) + beta;

			}
		}
	}
}

void totalLossFunction(DCGAN::Discriminator& name) {
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

void saveAllWeights(DCGAN::Discriminator& dis, DCGAN::Generator& gen)
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

void loadAllWeights(DCGAN::Discriminator& dis, DCGAN::Generator& gen)
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

void nn::Layer::backConv()
{
	Tensor4d<double> nK(k_s, k_s, i_ch, o_ch);
	nK.fill();

	Tensor3d<double> il = l_outputs->operator[](layer_id - 1); //X or input from past layer

	//gradient kernel

	for (size_t i = 0; i < X->getX(); i++) {
		for (size_t j = 0; j < X->getY(); j++) {
			for (size_t d = 0; d < o_ch; d++) {

				//double sum = 0;
				for (size_t a = 0; a < k_s; a++) {
					for (size_t b = 0; b < k_s; b++) {
						for (size_t c = 0; c < i_ch; c++)
						{
							nK(a, b, c, d) += X->operator()(i, j, d) * il(i * str + a, j * str + b, c);
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
					sum_dV(a, b, c, d) += nK(a, b, c, d);
				}
			}
		}
	}


}

void nn::Layer::backTransposeConv()
{
}

void nn::Layer::backBatchNorm()
{
}

//for (unsigned int li = 0; li < layers.size(); li++)
		//{
		//	std::ifstream read_second(filename);
		//
		//	std::string id_li = (std::string)typeid(*this).name() + " Layer " + std::to_string(li);
		//
		//	std::string line;
		//
		//	for (int curLine = 0; std::getline(read_second, line); curLine++) {
		//		if (line.find(id_li) != std::string::npos) 
		//		{
		//			//std::cout << "found: " << id_li << " line: " << curLine << std::endl;
		//
		//			for (size_t i = 0; i < layers[li]->V.getX(); i++) {
		//				for (size_t j = 0; j < layers[li]->V.getY(); j++) {
		//					for (size_t k = 0; k < layers[li]->V.getZ(); k++) {
		//						for (size_t l = 0; l < layers[li]->V.getD(); l++) 
		//						{
		//							char ch;
		//							std::string double_str = "";
		//							while (read_second.get(ch)) {
		//								if(ch == ';'){
		//									break;
		//								}
		//								double_str += ch;
		//							}
		//							//std::cout << double_str<<std::endl;
		//							layers[li]->V(i, j, k, l) = std::stod(double_str);
		//						}
		//					}
		//				}
		//			}
		//			break;
		//		}
		//	}
		//	read_second.close();
		//}