#pragma once
#include <iostream>

template<typename T>
class Tensor3d {
private:
    T*** tv;
    size_t x, y, z;

public:
    Tensor3d()
    {
        x = y = z = 0;
        tv = nullptr;
    }

    Tensor3d(size_t x, size_t y, size_t z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        tv = new T * *[x];
        for (size_t i = 0; i < x; i++) {
            tv[i] = new T * [y];
            for (size_t j = 0; j < y; j++) {
                tv[i][j] = new T[z];
            }
        }
    }

    ~Tensor3d()
    {
        if (tv != nullptr) {
            for (size_t i = 0; i < x; i++) {
                for (size_t j = 0; j < y; j++) {
                    delete[] tv[i][j];
                }
                delete[] tv[i];
            }
            delete[]tv;
        }
    }

    size_t getX() { return x; }
    size_t getY() { return y; }
    size_t getZ() { return z; }

    void fill(T value = 0)
    {
        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                for (size_t k = 0; k < z; k++) {
                    this->tv[i][j][k] = value;
                }
            }
        }
    }

    T& operator()(size_t x, size_t y, size_t z)
    {
        return tv[x][y][z];
    }
    Tensor3d& operator = (const Tensor3d& other)
    {

        if (tv != nullptr) {
            for (size_t i = 0; i < x; i++) {
                for (size_t j = 0; j < y; j++) {
                    delete[] tv[i][j];
                }
                delete[] tv[i];
            }
            delete[] tv;
        }

        x = other.x;
        y = other.y;
        z = other.z;

        tv = new T * *[x];
        for (size_t i = 0; i < x; i++) {
            tv[i] = new T * [y];
            for (size_t j = 0; j < y; j++) {
                tv[i][j] = new T[z];
            }
        }

        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                for (size_t k = 0; k < z; k++) {
                    this->tv[i][j][k] = other.tv[i][j][k];
                }
            }
        }

        return *this;
    }

    void printTensorValues()
    {
        if (x == 0) {
            std::cout << "No values!" << std::endl;
        }
        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                std::cout << "xy$(" << i << ":" << j << "): ";
                for (size_t k = 0; k < z; k++) {
                    std::cout << tv[i][j][k] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
};

template<typename T>
class Tensor4d {
private:
    T**** tv;
    size_t x, y, z, d;
public:
    Tensor4d()
    {
        x = y = z = d = 0;
        tv = nullptr;
    }

    Tensor4d(size_t x, size_t y, size_t z, size_t d)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->d = d;


        tv = new T * **[x];
        for (size_t i = 0; i < x; i++) {
            tv[i] = new T * *[y];
            for (size_t j = 0; j < y; j++) {
                tv[i][j] = new T * [z];
                for (size_t k = 0; k < z; k++) {
                    tv[i][j][k] = new T[d];
                }
            }
        }
    }

    ~Tensor4d()
    {
        if (tv != nullptr) {
            for (size_t i = 0; i < x; i++) {
                for (size_t j = 0; j < y; j++) {
                    for (size_t k = 0; k < z; k++) {
                        delete[] tv[i][j][k];
                    }
                    delete[] tv[i][j];
                }
                delete[] tv[i];
            }
            delete[]tv;
        }
    }

    size_t getX() { return x; }
    size_t getY() { return y; }
    size_t getZ() { return z; }
    size_t getD() { return d; }

    void fill(T value = 0)
    {
        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                for (size_t k = 0; k < z; k++) {
                    for (size_t l = 0; l < d; l++)
                    {
                        this->tv[i][j][k][l] = value;
                    }
                }
            }
        }
    }

    T& operator()(size_t x, size_t y, size_t z, size_t d)
    {
        return tv[x][y][z][d];
    }

    Tensor4d& operator = (const Tensor4d& other)
    {

        if (tv != nullptr) {
            for (size_t i = 0; i < x; i++) {
                for (size_t j = 0; j < y; j++) {
                    for (size_t k = 0; k < z; k++) {
                        delete[] tv[i][j][k];
                    }
                    delete[] tv[i][j];
                }
                delete[] tv[i];
            }
            delete[]tv;
        }

        x = other.x;
        y = other.y;
        z = other.z;
        d = other.d;

        tv = new T * **[x];
        for (size_t i = 0; i < x; i++) {
            tv[i] = new T * *[y];
            for (size_t j = 0; j < y; j++) {
                tv[i][j] = new T * [z];
                for (size_t k = 0; k < z; k++) {
                    tv[i][j][k] = new T[d];
                }
            }
        }

        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                for (size_t k = 0; k < z; k++) {
                    for (size_t l = 0; l < d; l++) {
                        this->tv[i][j][k][l] = other.tv[i][j][k][l];
                    }
                }
            }
        }

        return *this;

    }

    void printTensorValues()
    {
        if (x == 0) {
            std::cout << "No values!" << std::endl;
        }
        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                for (size_t k = 0; k < z; k++) {
                    std::cout << "xyz$(" << i << ":" << j << ":" << k << "): ";
                    for (size_t l = 0; l < d; l++) {
                        std::cout << tv[i][j][k][l] << " ";
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
};