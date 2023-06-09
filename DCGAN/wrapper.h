#pragma once
#include <iostream>
#include <chrono>

#include "neuralnetwork.h"

namespace WrapperCLI {
    namespace Tensor 
    {
        template<typename T>
        public ref class Tensor3d_CLI
        {
        private:
            Tensor3d<T>* m_pTensor3d;
        public:
            Tensor3d_CLI() {
                m_pTensor3d = new Tensor3d<T>;
            }

            Tensor3d_CLI(size_t x, size_t y, size_t z) {
                m_pTensor3d = new Tensor3d<T>(x, y, z);
            }

            virtual ~Tensor3d_CLI() {
                if (m_pTensor3d != nullptr) {
                    delete m_pTensor3d;
                }
            }

            !Tensor3d_CLI() {
                if (m_pTensor3d != nullptr) {
                    delete m_pTensor3d;
                }
            }

            size_t getX() { return m_pTensor3d->getX(); }
            size_t getY() { return m_pTensor3d->getY(); }
            size_t getZ() { return m_pTensor3d->getZ(); }

            void fill(T value) {
                m_pTensor3d->fill(value);
            }

            void appendPadding(size_t pad) {
                m_pTensor3d->appendPadding(pad);
            }

            void interweave() {
                m_pTensor3d->interweave();
            }

            void appendTransposedPadding(size_t pad)
            {
                m_pTensor3d->appendTransposedPadding();
            }

            T& operator()(size_t x, size_t y, size_t z) {
                return m_pTensor3d->operator()(x, y, z);
            }

            Tensor3d_CLI% operator = (const Tensor3d_CLI% other) {
                m_pTensor3d->operator=(*other.m_pTensor3d);
                return *this;
            }

            Tensor3d<T>& getTensor3d() {
                return *m_pTensor3d;
            }

            void printTensorValues() {
                m_pTensor3d->printTensorValues();
            }

        };


        template<typename T>
        public ref class Tensor4d_CLI
        {
        private:
            Tensor4d<T>* m_pTensor4d;
        public:
            Tensor4d_CLI() {
                m_pTensor4d = new Tensor4d<T>;
            }

            Tensor4d_CLI(size_t x, size_t y, size_t z, size_t d) {
                m_pTensor4d = new Tensor4d<T>(x, y, z, d);
            }

            virtual ~Tensor4d_CLI() {
                if (m_pTensor4d != nullptr) {
                    delete m_pTensor4d;
                }
            }

            !Tensor4d_CLI() {
                if (m_pTensor4d != nullptr) {
                    delete m_pTensor4d;
                }
            }

            size_t getX() { return m_pTensor4d->getX(); }
            size_t getY() { return m_pTensor4d->getY(); }
            size_t getZ() { return m_pTensor4d->getZ(); }
            size_t getD() { return m_pTensor4d->getD(); }

            void fill(T value) {
                m_pTensor4d->fill(value);
            }

            void rotate180() {
                m_pTensor4d->rotate180();
            }

            T& operator()(size_t x, size_t y, size_t z, size_t d) {
                return m_pTensor4d->operator()(x, y, z, d);
            }

            Tensor4d_CLI% operator = (const Tensor4d_CLI% other) {
                m_pTensor4d->operator=(*other.m_pTensor4d);
                return *this;
            }

            Tensor4d<T>& getTensor4d() {
                return *m_pTensor4d;
            }

            void printTensorValues() {
                m_pTensor4d->printTensorValues();
            }
        };
    };

    namespace NeuralNetworkCLI 
    {
        public ref class Discriminator_CLI
        {
        private:

            NeuralNetwork::Discriminator* m_pDiscriminator;

        public:

            Discriminator_CLI(System::String^ gName, size_t iBatch, double iLearning_rate, double iMomentum, double iDeviation)
            {
                std::string name = msclr::interop::marshal_as<std::string>(gName);
                m_pDiscriminator = new NeuralNetwork::Discriminator(name, iBatch, iLearning_rate, iMomentum, iDeviation);
            }

            virtual ~Discriminator_CLI() {
                if (m_pDiscriminator != nullptr) {
                    delete m_pDiscriminator;
                }
            }

            !Discriminator_CLI() {
                if (m_pDiscriminator != nullptr) {
                    delete m_pDiscriminator;
                }
            }

            NeuralNetwork::Discriminator& getPointerToDiscriminator() {
                return *m_pDiscriminator;
            }

            void forward(Tensor::Tensor3d_CLI<double>% input) {
                m_pDiscriminator->forward(input.getTensor3d());
            }

            void backward() {
                m_pDiscriminator->backward();
            }

            void clearOutputs() {
                m_pDiscriminator->clearOutputs();
            }

            void countBatchError() {
                m_pDiscriminator->countBatchError();
            }

            double getError() {
                return m_pDiscriminator->getError();
            }

            void updateAllParameters() {
                m_pDiscriminator->updateAllParameters();
            }

            void saveAllWeights() {
                m_pDiscriminator->saveAllWeights();
            }

            void loadAllWeights() {
                m_pDiscriminator->loadAllWeights();
            }


        };

        public ref class Generator_CLI
        {
        private:

            NeuralNetwork::Generator* m_pGenerator;

        public:

            Generator_CLI(System::String^ gName) {
                std::string name = msclr::interop::marshal_as<std::string>(gName);
                m_pGenerator = new NeuralNetwork::Generator(name);
            }

            Generator_CLI(System::String^ gName, size_t iBatch, double iLearning_rate, double iMomentum, double iDeviation)
            {
                std::string name = msclr::interop::marshal_as<std::string>(gName);
                m_pGenerator = new NeuralNetwork::Generator(name, iBatch, iLearning_rate, iMomentum, iDeviation);
            }

            virtual ~Generator_CLI() {
                if (m_pGenerator != nullptr) {
                    delete m_pGenerator;
                }
            }

            !Generator_CLI() {
                if (m_pGenerator != nullptr) {
                    delete m_pGenerator;
                }
            }

            NeuralNetwork::Generator& getPointerToDiscriminator() {
                return *m_pGenerator;
            }

            void setPointerToDiscriminator(Discriminator_CLI% disc_link) {
                m_pGenerator->setPointerToDiscriminator(disc_link.getPointerToDiscriminator());
            }

            void forward(Tensor::Tensor3d_CLI<double>% input) {
                m_pGenerator->forward(input.getTensor3d());
            }

            void loadAllWeights() {
                m_pGenerator->loadAllWeights();
            }

            void saveAllWeights() {
                m_pGenerator->saveAllWeights();
            }

            
            Tensor3d<double>& getNeurons() {
                return m_pGenerator->getNeurons();
            }

            double getError() {
                return m_pGenerator->getError();
            }

            void countBatchError() {
                m_pGenerator->countBatchError();
            }
        };

        void saveAllWeights(Discriminator_CLI% d, Generator_CLI% g) {
            NeuralNetwork::saveAllWeights(d.getPointerToDiscriminator(), g.getPointerToDiscriminator());
        };
    };

    namespace ImageProcessingCLI
    {
        void getImageValues(Tensor::Tensor3d_CLI<double>% iX, System::String^ wfilename)
        {
            std::wstring filename = msclr::interop::marshal_as<std::wstring>(wfilename);
            ImageProcessing::getImageValues(iX.getTensor3d(), filename);
        };
    };

    namespace setTimer {

        class Timer {
        private:
            std::chrono::steady_clock::time_point start;
            std::chrono::steady_clock::time_point end;
        public:
            void setTimer() {
                start = std::chrono::steady_clock::now();
            }
            std::chrono::milliseconds getTime() {
                end = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                return duration;
            }
        };

        public ref class Timer_CLI
        {
        private:

            Timer* m_pTimer;

        public:
            Timer_CLI() {
                m_pTimer = new Timer;
            }
            virtual ~Timer_CLI() {
                if (m_pTimer != nullptr) {
                    delete m_pTimer;
                }
            }
            !Timer_CLI() {
                if (m_pTimer != nullptr) {
                    delete m_pTimer;
                }
            }
            void setTimer() {
                m_pTimer->setTimer();
            }
            std::chrono::milliseconds getTime() {
                return m_pTimer->getTime();
            }

        };
    };
};

