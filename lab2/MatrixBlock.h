#ifndef MATRIXBLOCK_H
#define MATRIXBLOCK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

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

private:
    unsigned blockRows_;    // Количество строк в блоке
    unsigned blockCols_;    // Количество столбцов в блоке
    unsigned numBlocksRows_; // Количество блоков по строкам
    unsigned numBlocksCols_; // Количество блоков по столбцам
    std::vector<std::vector<std::vector<T>>> blocks_;
};

#endif // MATRIXBLOCK_H
