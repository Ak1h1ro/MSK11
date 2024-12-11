#include "MatrixDiagonal.h"

template<typename T>
MatrixDiagonal<T>::MatrixDiagonal(int size)
    : matrixSize(size), realDist(1.0, 10.0), intDist(1, 10) {
    matrix.resize(matrixSize, std::vector<T>(matrixSize, 0)); // Инициализация матрицы нулями
    std::random_device rd;
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
    for (int i = 0; i < matrixSize; ++i) {
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
    if (offset < 1 || offset >= matrixSize) {
        throw std::invalid_argument("Смещение должно быть в пределах от 1 до размера матрицы.");
    }
    for (int i = offset; i < matrixSize; ++i) {
        matrix[i][i - offset] = 0; // Инициализация нулями перед заполнением
    }
}

// Метод для заполнения нижней диагонали случайными значениями
template<typename T>
void MatrixDiagonal<T>::fillLowerDiagonalRandom(int offset) {
    for (int i = offset; i < matrixSize; ++i) {
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
    if (offset < 1 || offset >= matrixSize) {
        throw std::invalid_argument("Смещение должно быть в пределах от 1 до размера матрицы.");
    }

    for (int i = 0; i < matrixSize - offset; ++i) {
        matrix[i][i + offset] = 0; // Инициализация нулями перед заполнением верхней диагонали
    }
}

// Новый метод для заполнения верхней диагонали случайными значениями
template<typename T>
void MatrixDiagonal<T>::fillUpperDiagonalRandom(int offset) {
    for (int i = 0; i < matrixSize - offset; ++i) {
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
    outFile << matrixSize << std::endl; // Записываем размер матрицы

    // Записываем главную диагональ
    for (int i = 0; i < matrixSize; ++i) {
        outFile << matrix[i][i] << " ";
    }
    outFile << std::endl;

    // Записываем верхние диагонали
    for (int offset = 1; offset < matrixSize; ++offset) {
        bool hasUpperDiagonal = false;
        for (int i = 0; i < matrixSize - offset; ++i) {
            if (matrix[i][i + offset] != 0) { // Проверяем, есть ли заполненные элементы
                hasUpperDiagonal = true;
                break;
            }
        }
        if (hasUpperDiagonal) {
            outFile << "+ " << offset << " ";
            for (int i = 0; i < matrixSize - offset; ++i) {
                outFile << matrix[i][i + offset] << " ";
            }
            outFile << std::endl;
        }
    }

    // Записываем нижние диагонали
    for (int offset = 1; offset < matrixSize; ++offset) {
        bool hasLowerDiagonal = false;
        for (int i = offset; i < matrixSize; ++i) {
            if (matrix[i][i - offset] != 0) { // Проверяем, есть ли заполненные элементы
                hasLowerDiagonal = true;
                break;
            }
        }
        if (hasLowerDiagonal) {
            outFile << "- " << offset << " ";
            for (int i = offset; i < matrixSize; ++i) {
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

    inFile >> matrixSize; // Считываем размер матрицы
    matrix.resize(matrixSize, std::vector<T>(matrixSize, 0)); // Инициализируем матрицу нулями

    // Считываем главную диагональ
    for (int i = 0; i < matrixSize; ++i) {
        inFile >> matrix[i][i]; // Считываем главную диагональ
    }

    // Считываем верхние и нижние диагонали
    while (!inFile.eof()) {
        char sign;
        int offset;
        inFile >> sign >> offset;

        if (sign == '+') { // Верхняя диагональ
            for (int i = 0; i < matrixSize - offset; ++i) {
                inFile >> matrix[i][i + offset]; // Считываем верхнюю диагональ
            }
        } else if (sign == '-') { // Нижняя диагональ
            for (int i = offset; i < matrixSize; ++i) {
                inFile >> matrix[i][i - offset]; // Считываем нижнюю диагональ
            }
        }
    }

    inFile.close();
    return true;
}

template<typename T> //доступ к элементам матрицы
T& MatrixDiagonal<T>::operator()(unsigned i, unsigned j) {
    if (i >= matrixSize || j >= matrixSize) {
        throw std::out_of_range("Индексы выходят за пределы.");
    }
    if (i == j) {
        return matrix[i][j]; // Главная диагональ
    } else if (i + 1 == j) {
        return matrix[i][j]; // Верхняя диагональ
    } else if (i == j + 1) {
        return matrix[j][i]; // Нижняя диагональ
    } else {
        static T zero = 0; // Нулевое значение для не диагональных элементов
        return zero;
    }
}


template<typename T>
unsigned MatrixDiagonal<T>::size() const {
    return matrixSize; // Возвращаем размер матрицы
}


template<typename T> //произведение Кронекера
MatrixDiagonal<T> MatrixDiagonal<T>::kroneckerMultiplication(const MatrixDiagonal<T>& other) const {
    unsigned newSize = matrixSize * other.matrixSize; // Новый размер матрицы
    MatrixDiagonal<T> result(newSize); // Создаем новую матрицу для результата

    for (unsigned i = 0; i < matrixSize; ++i) {
        for (unsigned j = 0; j < other.matrixSize; ++j) {
            // Произведение элементов главной диагонали
            result(i * other.matrixSize + j, i * other.matrixSize + j) = this->matrix[i][i] * other.matrix[j][j];

            // Если есть верхние и нижние диагонали, добавляем их
            if (i < matrixSize - 1) {
                result(i * other.matrixSize + j, (i + 1) * other.matrixSize + j) = this->matrix[i][i + 1] * other.matrix[j][j];
            }
            if (j < other.matrixSize - 1) {
                result(i * other.matrixSize + j, i * other.matrixSize + (j + 1)) = this->matrix[i][i] * other.matrix[j][j + 1];
            }
            if (i < matrixSize - 1 && j < other.matrixSize - 1) {
                result((i + 1) * other.matrixSize + j, i * other.matrixSize + j) = this->matrix[i + 1][i] * other.matrix[j][j];
                result(i * other.matrixSize + (j + 1), i * other.matrixSize + j) = this->matrix[i][i] * other.matrix[j + 1][j];
            }
        }
    }

    return result;
}



// Явная специализация для double
template class MatrixDiagonal<double>;
template class MatrixDiagonal<int>;
