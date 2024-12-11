#include "MatrixDiagonal.h"

template<typename T>
MatrixDiagonal<T>::MatrixDiagonal(int size)
    : size(size), realDist(1.0, 100.0), intDist(1, 100) {
    matrix.resize(size, std::vector<T>(size, 0)); // Инициализация матрицы нулями
    std::random_device rd;
    // Используйте текущее время в качестве seed для генератора
    rng.seed(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    fillMainDiagonalRandom(); // Заполнение главной диагонали случайными значениями при создании
}

// Деструктор
template <typename T>
MatrixDiagonal<T>::~MatrixDiagonal() {
    // Векторы автоматически освобождают память
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

template<typename T>
void MatrixDiagonal<T>::exportToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи.");
    }

    outFile << "MatrixDiagonal" << std::endl; // Записываем название класса
    outFile << size << std::endl; // Записываем размер матрицы

    // Записываем главную диагональ
    for (int i = 0; i < size; ++i) {
        outFile << matrix[i][i] << " ";
    }
    outFile << std::endl;

    // Записываем верхние диагонали
    for (int offset = 1; offset < size; ++offset) {
        bool hasUpperDiagonal = false;
        for (int i = 0; i < size - offset; ++i) {
            if (matrix[i][i + offset] != 0) { // Проверяем, есть ли заполненные элементы
                hasUpperDiagonal = true;
                break;
            }
        }
        if (hasUpperDiagonal) {
            outFile << "+ " << offset << " ";
            for (int i = 0; i < size - offset; ++i) {
                outFile << matrix[i][i + offset] << " ";
            }
            outFile << std::endl;
        }
    }

    // Записываем нижние диагонали
    for (int offset = 1; offset < size; ++offset) {
        bool hasLowerDiagonal = false;
        for (int i = offset; i < size; ++i) {
            if (matrix[i][i - offset] != 0) { // Проверяем, есть ли заполненные элементы
                hasLowerDiagonal = true;
                break;
            }
        }
        if (hasLowerDiagonal) {
            outFile << "- " << offset << " ";
            for (int i = offset; i < size; ++i) {
                outFile << matrix[i][i - offset] << " ";
            }
            outFile << std::endl;
        }
    }

    outFile.close();
}


template<typename T>
bool MatrixDiagonal<T>::importFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для чтения.");
    }

    std::string className;
    inFile >> className; // Считываем название класса
    if (className != "MatrixDiagonal") {
        std::cerr << "Неверный формат файла." << std::endl;
        return false;
    }

    inFile >> size; // Считываем размер матрицы
    matrix.resize(size, std::vector<T>(size, 0)); // Инициализируем матрицу нулями

    // Считываем главную диагональ
    for (int i = 0; i < size; ++i) {
        inFile >> matrix[i][i]; // Считываем главную диагональ
    }

    // Считываем верхние и нижние диагонали
    while (!inFile.eof()) {
        char sign;
        int offset;
        inFile >> sign >> offset;

        if (sign == '+') { // Верхняя диагональ
            for (int i = 0; i < size - offset; ++i) {
                inFile >> matrix[i][i + offset]; // Считываем верхнюю диагональ
            }
        } else if (sign == '-') { // Нижняя диагональ
            for (int i = offset; i < size; ++i) {
                inFile >> matrix[i][i - offset]; // Считываем нижнюю диагональ
            }
        }
    }

    inFile.close();
    return true;
}



// Явная специализация для double
template class MatrixDiagonal<double>;
template class MatrixDiagonal<int>;
