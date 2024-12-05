#ifndef MATRIXBLOCK_H
#define MATRIXBLOCK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <memory>
#include <unordered_map>
#include "Matrix.h" // Подключаем MatrixDense

template <typename T>
class MatrixBlock {
public:
    virtual ~MatrixBlock() = default;

    virtual void fillRandom() = 0;
    virtual void print() const = 0;
    virtual void exportToFile(const std::string& filename) const = 0;
    virtual bool importFromFile(const std::string& filename) = 0;
};

template <typename T>
class BlockMatrix : public MatrixBlock<T> {
public:
    BlockMatrix(unsigned blockRows, unsigned blockCols, unsigned numBlocksRows, unsigned numBlocksCols);
    ~BlockMatrix();

    void fillRandom() override;
    void print() const override;
    void exportToFile(const std::string& filename) const override;
    bool importFromFile(const std::string& filename) override;

    void scalarMultiply(T scalar);
    BlockMatrix<T> elementWiseMultiply(const BlockMatrix<T>& other) const;
    BlockMatrix<T> operator*(const BlockMatrix<T>& other) const;
    BlockMatrix<T> operator+(const BlockMatrix<T>& other) const;
    BlockMatrix<T> operator-(const BlockMatrix<T>& other) const;
    BlockMatrix<T> transpose() const;

private:
    unsigned blockRows_;
    unsigned blockCols_;
    unsigned numBlocksRows_;
    unsigned numBlocksCols_;

    // Используем умные указатели для хранения блоков MatrixDense
    std::vector<std::vector<std::shared_ptr<MatrixDense<T>>>> blocks_;

    // Хранение уникальных элементов для оптимизации памяти
    std::unordered_map<T, std::shared_ptr<T>> uniqueElements_;
};

#endif // MATRIXBLOCK_H
