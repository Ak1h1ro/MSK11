#ifndef MATRIXDIAGONAL_H
#define MATRIXDIAGONAL_H

#include <vector>
#include <iostream>
#include <random>
#include <stdexcept>
#include <type_traits>
#include <fstream>
#include <chrono>

template<typename T>
class MatrixDiagonal {
public:
    MatrixDiagonal(int size);
    ~MatrixDiagonal();
    void addLowerDiagonal(int offset);
    void addUpperDiagonal(int offset);
    void fillLowerDiagonalRandom(int offset);
    void fillUpperDiagonalRandom(int offset);
    void fillMainDiagonalRandom();
    void print() const;
    void exportToFile(const std::string& filename) const; // Экспорт в файл
    bool importFromFile(const std::string& filename); // Импорт из файла
    T& operator()(unsigned i, unsigned j); // Метод доступа к элементам матрицы
    unsigned size() const; // Метод для получения размера матрицы
    MatrixDiagonal<T> kroneckerMultiplication(const MatrixDiagonal<T>& other) const; // Метод для произведения Кронекера двух диагональных матриц
    MatrixDiagonal<T> scalarMultiply(T scalar) const; // Умножение на скаляр
    MatrixDiagonal<T> elementWiseMultiply(const MatrixDiagonal<T>& other) const; // Поэлементное умножение
    MatrixDiagonal<T> operator*(const MatrixDiagonal<T>& other) const; // Матричное умножение


private:
    int matrixSize;
    std::vector<std::vector<T>> matrix; // Матрица инициализируется нулями
    std::mt19937 rng; // Генератор случайных чисел
    std::uniform_real_distribution<double> realDist; // Распределение для генерации случайных чисел с плавающей запятой
    std::uniform_int_distribution<int> intDist; // Распределение для генерации случайных целых чисел
};

// Явная специализация для double
extern template class MatrixDiagonal<double>;

#endif // MATRIXDIAGONAL_H
