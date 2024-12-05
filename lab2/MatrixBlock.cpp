#include "MatrixBlock.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
BlockMatrix<T>::BlockMatrix(unsigned blockRows, unsigned blockCols, unsigned numBlocksRows, unsigned numBlocksCols)
    : blockRows_(blockRows), blockCols_(blockCols), numBlocksRows_(numBlocksRows), numBlocksCols_(numBlocksCols) {

    // Инициализация блоков с использованием shared_ptr для управления памятью
    blocks_.resize(numBlocksRows_, std::vector<std::shared_ptr<MatrixDense<T>>>(numBlocksCols_));

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            blocks_[i][j] = std::make_shared<MatrixDense<T>>(blockRows_, blockCols_);
        }
    }
}

template <typename T>
BlockMatrix<T>::~BlockMatrix() {
    // Умные указатели автоматически очищают память
}

template <typename T>
void BlockMatrix<T>::fillRandom() {
    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            auto& block = *blocks_[i][j]; // Получаем доступ к блоку

            for (unsigned k = 0; k < block.rows(); ++k) {
                for (unsigned l = 0; l < block.cols(); ++l) {
                    T value = static_cast<T>(std::rand() % 100 + 1);

                    // Используем уникальные элементы
                    if (uniqueElements_.find(value) == uniqueElements_.end()) {
                        uniqueElements_[value] = std::make_shared<T>(value);
                    }

                    block(k, l) = *uniqueElements_[value];
                }
            }
        }
    }
}

template <typename T>
void BlockMatrix<T>::print() const {
    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            std::cout << "Block (" << i << ", " << j << "):" << std::endl;
            blocks_[i][j]->print(); // Используем метод print из MatrixDense
        }
    }
}

template <typename T>
void BlockMatrix<T>::exportToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    outFile << "BlockMatrix" << std::endl; // Название класса
    outFile << blockRows_ << " " << blockCols_ << " " << numBlocksRows_ << " " << numBlocksCols_ << std::endl; // Размеры матрицы и блоков

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            for (unsigned k = 0; k < blockRows_; ++k) {
                for (unsigned l = 0; l < blockCols_; ++l) {
                    // Используем разыменование для доступа к элементам MatrixDense
                    outFile << (*blocks_[i][j])(k, l) << " ";
                }
                outFile << std::endl;
            }
        }
    }

    outFile.close();
}

template <typename T>
bool BlockMatrix<T>::importFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return false;
    }

    std::string className;
    inFile >> className;
    if (className != "BlockMatrix") {
        std::cerr << "Class name does not match!" << std::endl;
        return false;
    }

    inFile >> blockRows_ >> blockCols_ >> numBlocksRows_ >> numBlocksCols_;

    // Измените инициализацию blocks_ на использование shared_ptr
    blocks_.resize(numBlocksRows_, std::vector<std::shared_ptr<MatrixDense<T>>>(numBlocksCols_));

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            // Создаем новый объект MatrixDense для каждого блока
            blocks_[i][j] = std::make_shared<MatrixDense<T>>(blockRows_, blockCols_);
            for (unsigned k = 0; k < blockRows_; ++k) {
                for (unsigned l = 0; l < blockCols_; ++l) {
                    T value;
                    inFile >> value; // Считываем значение из файла
                    (*blocks_[i][j])(k, l) = value; // Записываем значение в матрицу
                }
            }
        }
    }

    inFile.close();
    return true;
}

template <typename T>
void BlockMatrix<T>::scalarMultiply(T scalar) {
    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            for (unsigned k = 0; k < blockRows_; ++k) {
                for (unsigned l = 0; l < blockCols_; ++l) {
                    // Используем разыменование для доступа к элементам MatrixDense
                    (*blocks_[i][j])(k, l) *= scalar;
                }
            }
        }
    }
}

template <typename T>
BlockMatrix<T> BlockMatrix<T>::elementWiseMultiply(const BlockMatrix<T>& other) const {
    if (numBlocksRows_ != other.numBlocksRows_ || numBlocksCols_ != other.numBlocksCols_ ||
        blockRows_ != other.blockRows_ || blockCols_ != other.blockCols_) {
        throw std::invalid_argument("Matrices must have the same dimensions for element-wise multiplication.");
    }

    BlockMatrix<T> result(blockRows_, blockCols_, numBlocksRows_, numBlocksCols_);

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            for (unsigned k = 0; k < blockRows_; ++k) {
                for (unsigned l = 0; l < blockCols_; ++l) {
                    // Используем разыменование для доступа к элементам MatrixDense
                    (*result.blocks_[i][j])(k, l) = (*blocks_[i][j])(k, l) * (*other.blocks_[i][j])(k, l);
                }
            }
        }
    }

    return result;
}

template <typename T>
BlockMatrix<T> BlockMatrix<T>::operator*(const BlockMatrix<T>& other) const {
    if (numBlocksCols_ != other.numBlocksRows_ || blockCols_ != other.blockRows_) {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication.");
    }

    BlockMatrix<T> result(blockRows_, other.blockCols_, numBlocksRows_, other.numBlocksCols_);

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < other.numBlocksCols_; ++j) {
            for (unsigned k = 0; k < numBlocksCols_; ++k) {
                for (unsigned m = 0; m < blockRows_; ++m) {
                    for (unsigned n = 0; n < other.blockCols_; ++n) {
                        // Правильный доступ к элементам MatrixDense через разыменование
                        result.blocks_[i][j]->operator()(m, n) +=
                            blocks_[i][k]->operator()(m, n) * other.blocks_[k][j]->operator()(m, n);
                    }
                }
            }
        }
    }

    return result;
}


template <typename T>
BlockMatrix<T> BlockMatrix<T>::operator+(const BlockMatrix<T>& other) const {
    if (numBlocksRows_ != other.numBlocksRows_ || numBlocksCols_ != other.numBlocksCols_ ||
        blockRows_ != other.blockRows_ || blockCols_ != other.blockCols_) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition.");
    }

    BlockMatrix<T> result(blockRows_, blockCols_, numBlocksRows_, numBlocksCols_);

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            for (unsigned k = 0; k < blockRows_; ++k) {
                for (unsigned l = 0; l < blockCols_; ++l) {
                    // Используем разыменование для доступа к элементам MatrixDense
                    (*result.blocks_[i][j])(k, l) = (*blocks_[i][j])(k, l) + (*other.blocks_[i][j])(k, l);
                }
            }
        }
    }

    return result;
}

template <typename T>
BlockMatrix<T> BlockMatrix<T>::operator-(const BlockMatrix<T>& other) const {
    if (numBlocksRows_ != other.numBlocksRows_ || numBlocksCols_ != other.numBlocksCols_ ||
        blockRows_ != other.blockRows_ || blockCols_ != other.blockCols_) {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
    }

    BlockMatrix<T> result(blockRows_, blockCols_, numBlocksRows_, numBlocksCols_);

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            for (unsigned k = 0; k < blockRows_; ++k) {
                for (unsigned l = 0; l < blockCols_; ++l) {
                    // Используем разыменование для доступа к элементам MatrixDense
                    (*result.blocks_[i][j])(k, l) = (*blocks_[i][j])(k, l) - (*other.blocks_[i][j])(k, l);
                }
            }
        }
    }

    return result;
}

template <typename T>
BlockMatrix<T> BlockMatrix<T>::transpose() const {
    BlockMatrix<T> result(blockCols_, blockRows_, numBlocksCols_, numBlocksRows_);

    for (unsigned i = 0; i < numBlocksRows_; ++i) {
        for (unsigned j = 0; j < numBlocksCols_; ++j) {
            for (unsigned k = 0; k < blockRows_; ++k) {
                for (unsigned l = 0; l < blockCols_; ++l) {
                    // Используем разыменование для доступа к элементам MatrixDense
                    (*result.blocks_[j][i])(l, k) = (*blocks_[i][j])(k, l);
                }
            }
        }
    }

    return result;
}


template class BlockMatrix<int>;
template class BlockMatrix<double>;
