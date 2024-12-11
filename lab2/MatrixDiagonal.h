#ifndef MATRIXDIAGONAL_H
#define MATRIXDIAGONAL_H

#include <vector>
#include <iostream>
#include <random>
#include <stdexcept>
#include <type_traits>

template<typename T>
class MatrixDiagonal {
public:
    MatrixDiagonal(int size);
    void addLowerDiagonal(int offset);
    void addUpperDiagonal(int offset);
    void fillLowerDiagonalRandom(int offset);
    void fillUpperDiagonalRandom(int offset);
    void fillMainDiagonalRandom();
    void print() const;

private:
    int size;
    std::vector<std::vector<T>> matrix; // Матрица инициализируется нулями
    std::mt19937 rng; // Генератор случайных чисел
    std::uniform_real_distribution<double> realDist; // Распределение для генерации случайных чисел с плавающей запятой
    std::uniform_int_distribution<int> intDist; // Распределение для генерации случайных целых чисел
};

// Явная специализация для double
extern template class MatrixDiagonal<double>;

#endif // MATRIXDIAGONAL_H
