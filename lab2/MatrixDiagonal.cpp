#include "MatrixDiagonal.h"

// Конструктор
template <typename T>
MatrixDiagonal<T>::MatrixDiagonal(unsigned size) : _size(size),
    _mainDiagonal(size),
    _upperDiagonal(size - 1),
    _lowerDiagonal(size - 1) {
    if (size == 0) {
        throw std::invalid_argument("Size must be greater than zero.");
    }
}

// Деструктор
template <typename T>
MatrixDiagonal<T>::~MatrixDiagonal() {
    // Векторы автоматически освобождают память
}

// Метод для отображения матрицы
template <typename T>
void MatrixDiagonal<T>::print() const {
    for (unsigned i = 0; i < _size; ++i) {
        for (unsigned j = 0; j < _size; ++j) {
            if (i == j) {
                std::cout << _mainDiagonal[i] << " "; // Главная диагональ
            } else if (i + 1 == j) {
                std::cout << _upperDiagonal[i] << " "; // Верхняя диагональ
            } else if (i == j + 1) {
                std::cout << _lowerDiagonal[j] << " "; // Нижняя диагональ
            } else {
                std::cout << "0 "; // Нулевой элемент
            }
        }
        std::cout << std::endl;
    }
}

// Метод для заполнения матрицы случайными значениями
template <typename T>
void MatrixDiagonal<T>::fillRandom() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Инициализация генератора случайных чисел

    for (unsigned i = 0; i < _size; ++i) {
        _mainDiagonal[i] = static_cast<double>(std::rand() % 100 + 1); // Случайное значение от 1 до 100
        if (i < _size - 1) {
            _upperDiagonal[i] = static_cast<double>(std::rand() % 100 + 1); // Случайное значение для верхней диагонали
            _lowerDiagonal[i] = static_cast<double>(std::rand() % 100 + 1); // Случайное значение для нижней диагонали
        }
    }
}


// Явная специализация для double (если нужно)
template class MatrixDiagonal<double>;

