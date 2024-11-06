#include "MatrixBlock.h"

template <typename T>
BlockMatrix<T>::BlockMatrix(unsigned blockSize, unsigned numBlocks)
    : blockSize_(blockSize), numBlocks_(numBlocks) {
    blocks_.resize(numBlocks_, std::vector<std::vector<T>>(numBlocks_, std::vector<T>(blockSize_ * blockSize_)));
}

template <typename T>
BlockMatrix<T>::~BlockMatrix() {
    // Вектор автоматически очищает память
}

template <typename T>
void BlockMatrix<T>::fillRandom() {
    for (unsigned i = 0; i < numBlocks_; ++i) {
        for (unsigned j = 0; j < numBlocks_; ++j) {
            for (unsigned k = 0; k < blockSize_; ++k) {
                for (unsigned l = 0; l < blockSize_; ++l) {
                    blocks_[i][j][k * blockSize_ + l] = static_cast<T>(std::rand() % 100 + 1);
                }
            }
        }
    }
}

template <typename T>
void BlockMatrix<T>::print() const {
    for (unsigned i = 0; i < numBlocks_; ++i) {
        for (unsigned j = 0; j < numBlocks_; ++j) {
            std::cout << "Block (" << i << ", " << j << "):" << std::endl;
            for (unsigned k = 0; k < blockSize_; ++k) {
                for (unsigned l = 0; l < blockSize_; ++l) {
                    std::cout << blocks_[i][j][k * blockSize_ + l] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}


template class BlockMatrix<int>;
template class BlockMatrix<double>;
