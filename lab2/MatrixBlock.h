#ifndef MATRIXBLOCK_H
#define MATRIXBLOCK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
class MatrixBlock {
public:
    virtual ~MatrixBlock() = default;

    virtual void fillRandom() = 0;
    virtual void print() const = 0;
};

template <typename T>
class BlockMatrix : public MatrixBlock<T> {
public:
    BlockMatrix(unsigned blockSize, unsigned numBlocks);
    ~BlockMatrix();

    void fillRandom() override;
    void print() const override;

private:
    unsigned blockSize_;
    unsigned numBlocks_;
    std::vector<std::vector<std::vector<T>>> blocks_; // 3D вектор для хранения блоков
};

#endif // MATRIXBLOCK_H
