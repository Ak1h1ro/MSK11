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

// Метод доступа к элементам матрицы
template <typename T>
T& MatrixDiagonal<T>::operator()(unsigned i, unsigned j) {
    if (i >= _size || j >= _size) {
        throw std::out_of_range("Indexes out of range.");
    }
    if (i == j) {
        return _mainDiagonal[i]; // Главная диагональ
    } else if (i + 1 == j) {
        return _upperDiagonal[i]; // Верхняя диагональ
    } else if (i == j + 1) {
        return _lowerDiagonal[j]; // Нижняя диагональ
    } else {
        static T zero = 0; // Нулевое значение для не диагональных элементов
        return zero;
    }
}

// Метод для получения размера матрицы
template <typename T>
unsigned MatrixDiagonal<T>::size() const {
    return _size;
}

// Метод для экспорта матрицы в файл
template <typename T>
void MatrixDiagonal<T>::exportToFile(const char* filename) const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw std::runtime_error("Unable to open file for writing.");
    }

    outFile << "MatrixDiagonal" << std::endl; // Записываем название класса
    outFile << _size << std::endl; // Записываем размер матрицы

    for (unsigned i = 0; i < _size; ++i) {
        outFile << _mainDiagonal[i] << " ";
    }
    outFile << std::endl;

    for (unsigned i = 0; i < _size - 1; ++i) {
        outFile << _upperDiagonal[i] << " ";
    }
    outFile << std::endl;

    for (unsigned i = 0; i < _size - 1; ++i) {
        outFile << _lowerDiagonal[i] << " ";
    }

    outFile.close();
}



// Метод для импорта матрицы из файла
template <typename T>
bool MatrixDiagonal<T>::importFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        throw std::runtime_error("Unable to open file for reading.");
    }

    std::string className;
    inFile >> className; // Считываем название класса

    if (className != "MatrixDiagonal") {
        std::cerr << "Invalid file format." << std::endl;
        return false;
    }

    inFile >> _size; // Считываем размер матрицы

    _mainDiagonal.resize(_size);
    _upperDiagonal.resize(_size - 1);
    _lowerDiagonal.resize(_size - 1);

    for (unsigned i = 0; i < _size; ++i) {
        inFile >> _mainDiagonal[i]; // Считываем главную диагональ
    }

    for (unsigned i = 0; i < _size - 1; ++i) {
        inFile >> _upperDiagonal[i]; // Считываем верхнюю диагональ
    }

    for (unsigned i = 0; i < _size - 1; ++i) {
        inFile >> _lowerDiagonal[i]; // Считываем нижнюю диагональ
    }

    inFile.close();
    return true;
}

// Метод для произведения Кронекера двух диагональных матриц
template <typename T>
MatrixDiagonal<T> MatrixDiagonal<T>::kroneckerProduct(const MatrixDiagonal<T>& other) const {
    unsigned newSize = _size * other._size; // Новый размер матрицы
    MatrixDiagonal<T> result(newSize); // Создаем новую матрицу для результата

    for (unsigned i = 0; i < _size; ++i) {
        for (unsigned j = 0; j < other._size; ++j) {
            // Произведение элементов главной диагонали
            result(i * other._size + j, i * other._size + j) = this->_mainDiagonal[i] * other._mainDiagonal[j];

            // Если есть верхние и нижние диагонали, добавляем их
            if (i < _size - 1) {
                result(i * other._size + j, (i + 1) * other._size + j) = this->_upperDiagonal[i] * other._mainDiagonal[j];
            }
            if (j < other._size - 1) {
                result(i * other._size + j, i * other._size + (j + 1)) = this->_mainDiagonal[i] * other._upperDiagonal[j];
            }
            if (i < _size - 1 && j < other._size - 1) {
                result((i + 1) * other._size + j, i * other._size + j) = this->_lowerDiagonal[i] * other._mainDiagonal[j];
                result(i * other._size + (j + 1), i * other._size + j) = this->_mainDiagonal[i] * other._lowerDiagonal[j];
            }
        }
    }

    return result;
}

// Явная специализация для double (если нужно)
template class MatrixDiagonal<double>;

