#include "MatrixDiagonal.h"

// Конструктор класса
template<typename T>
MatrixDiagonal<T>::MatrixDiagonal(int size) : size(size), realDist(1.0, 10.0), intDist(1, 10) {
    matrix.resize(size, std::vector<T>(size, 0)); // Инициализация матрицы нулями
    std::random_device rd; // Получаем случайное число из устройства
    rng.seed(rd()); // Инициализация генератора случайных чисел
    fillMainDiagonalRandom(); // Заполнение главной диагонали случайными значениями при создании
}

// Метод для заполнения главной диагонали случайными значениями
template<typename T>
void MatrixDiagonal<T>::fillMainDiagonalRandom() {
    for (int i = 0; i < size; ++i) {
        if constexpr (std::is_integral<T>::value) {
            matrix[i][i] = intDist(rng); // Заполнение случайными целыми числами от 1 до 10
        } else {
            matrix[i][i] = static_cast<T>(realDist(rng)); // Заполнение случайными значениями от 1 до 10
        }
    }
}

// Метод для добавления нижней диагонали с заданным смещением
template<typename T>
void MatrixDiagonal<T>::addLowerDiagonal(int offset) {
    if (offset < 1 || offset >= size) {
        throw std::invalid_argument("Смещение должно быть в пределах от 1 до размера матрицы.");
    }
    for (int i = offset; i < size; ++i) {
        matrix[i][i - offset] = 0; // Инициализация нулями перед заполнением
    }
}

// Метод для заполнения нижней диагонали случайными значениями
template<typename T>
void MatrixDiagonal<T>::fillLowerDiagonalRandom(int offset) {
    for (int i = offset; i < size; ++i) {
        if constexpr (std::is_integral<T>::value) {
            matrix[i][i - offset] = intDist(rng); // Заполнение случайными целыми числами от 1 до 10
        } else {
            matrix[i][i - offset] = static_cast<T>(realDist(rng)); // Заполнение случайными значениями от 1 до 10
        }
    }
}

// Новый метод для добавления верхней диагонали с заданным смещением
template<typename T>
void MatrixDiagonal<T>::addUpperDiagonal(int offset) {
    if (offset < 1 || offset >= size) {
        throw std::invalid_argument("Смещение должно быть в пределах от 1 до размера матрицы.");
    }

    for (int i = 0; i < size - offset; ++i) {
        matrix[i][i + offset] = 0; // Инициализация нулями перед заполнением верхней диагонали
    }
}

// Новый метод для заполнения верхней диагонали случайными значениями
template<typename T>
void MatrixDiagonal<T>::fillUpperDiagonalRandom(int offset) {
    for (int i = 0; i < size - offset; ++i) {
        if constexpr (std::is_integral<T>::value) {
            matrix[i][i + offset] = intDist(rng); // Заполнение случайными целыми числами от 1 до 10
        } else {
            matrix[i][i + offset] = static_cast<T>(realDist(rng)); // Заполнение случайными значениями от 1 до 10
        }
    }
}

// Метод для вывода матрицы на экран
template<typename T>
void MatrixDiagonal<T>::print() const {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// Явная специализация для double
template class MatrixDiagonal<double>;
template class MatrixDiagonal<int>;
