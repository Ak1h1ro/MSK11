#ifndef MATRIX_DIAGONAL_H
#define MATRIX_DIAGONAL_H
#include <ctime>   // Для функции time()
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream> // Для std::ofstream

template <typename T = double>
class MatrixDiagonal {
private:
    unsigned _size; // Размер матрицы (количество строк и столбцов)
    std::vector<T> _mainDiagonal; // Вектор для главной диагонали
    std::vector<T> _upperDiagonal; // Вектор для верхней диагонали
    std::vector<T> _lowerDiagonal; // Вектор для нижней диагонали

public:
    MatrixDiagonal(unsigned size); // Конструктор
    ~MatrixDiagonal(); // Деструктор
    void print() const; // Метод для отображения матрицы
    void fillRandom(); // Метод для заполнения матрицы случайными значениями
    T& operator()(unsigned i, unsigned j); // Метод доступа к элементам матрицы
    unsigned size() const; // Метод для получения размера матрицы
    void exportToFile(const char* filename) const; // Экспорт в файл
    bool importFromFile(const std::string& filename); // Импорт из файла
    MatrixDiagonal<T> kroneckerProduct(const MatrixDiagonal<T>& other) const; // Метод для произведения Кронекера двух диагональных матриц
    MatrixDiagonal<T> scalarMultiply(T scalar) const; // Умножение на скаляр
    MatrixDiagonal<T> elementWiseMultiply(const MatrixDiagonal<T>& other) const; // Поэлементное умножение
    MatrixDiagonal<T> operator*(const MatrixDiagonal<T>& other) const; // Матричное умножение
    MatrixDiagonal<T> operator+(const MatrixDiagonal<T>& other) const; // Матричное сложение
    MatrixDiagonal<T> operator-(const MatrixDiagonal<T>& other) const; // Матричное вычитание
    MatrixDiagonal<T> transpose() const; // Транспонирование матрицы


};

#endif // MATRIX_DIAGONAL_H

