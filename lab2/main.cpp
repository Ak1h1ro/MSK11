#include <iostream>
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для функции time()
#include <fstream> // Для std::ofstream
#include "Matrix.h"
#include "MatrixBlock.h"
#include "MatrixDiagonal.h"

// Функция для заполнения матрицы случайными значениями
template <typename T>
void fillMatrix(MatrixDense<T>& matrix) {
    for (unsigned i = 0; i < matrix.rows(); ++i) {
        for (unsigned j = 0; j < matrix.cols(); ++j) {
            matrix(i, j) = static_cast<T>(std::rand() % 100 + 1); // Случайное значение от 1 до 100
        }
    }
}

int main() {
    try {
        // Инициализация генератора случайных чисел
        /*std::srand(static_cast<unsigned>(std::time(0)));

        // Создаем матрицы 3x3
        MatrixDense<double> matrixA(3, 3);
        MatrixDense<double> matrixB(3, 3);

        // Заполняем матрицы случайными значениями
        fillMatrix(matrixA);
        fillMatrix(matrixB);

        // Выводим матрицы A и B в консоль
        std::cout << "Generated matrix A:" << std::endl;
        matrixA.print();

        std::cout << "Generated matrix B:" << std::endl;
        matrixB.print();

        // Открываем файл для записи
        std::ofstream outFile("matrices.txt");
        if (!outFile) {
            throw std::runtime_error("The file could not be opened for writing");
        }

        // Записываем матрицы в файл с использованием метода exportToFile
        matrixA.exportToFile(outFile, "Matrix A:");
        matrixB.exportToFile(outFile, "\nMatrix B:");

        // Умножаем матрицу A на скаляр
        double scalar = 2.5; // Пример скаляра
        MatrixDense<double> scaledMatrix = matrixA.scalarMultiply(scalar);

        // Выводим результирующую матрицу на экран
        std::cout << "Scaled matrix A (multiplied by " << scalar << "):" << std::endl;
        scaledMatrix.print();

        // Записываем результирующую матрицу в файл
        scaledMatrix.exportToFile(outFile, "\nScaled matrix A (multiplied by " + std::to_string(scalar) + "):");

        // Поэлементное умножение матриц A и B
        MatrixDense<double> elementWiseResult = matrixA.elementWiseMultiply(matrixB);
        std::cout << "Element-wise multiplication of A and B:" << std::endl;
        elementWiseResult.print();
        elementWiseResult.exportToFile(outFile, "\nElement-wise multiplication of A and B:");

        // Матричное умножение матриц A и B
        MatrixDense<double> matrixResult = matrixA * matrixB;
        std::cout << "Matrix multiplication of A and B:" << std::endl;
        matrixResult.print();
        matrixResult.exportToFile(outFile, "\nMatrix multiplication of A and B:");

        // Матричное сложение
        MatrixDense<double> additionResult = matrixA + matrixB;
        std::cout << "Matrix addition of A and B:" << std::endl;
        additionResult.print();
        additionResult.exportToFile(outFile, "\nMatrix addition of A and B:");

        // Матричное вычитание
        MatrixDense<double> subtractionResult = matrixA - matrixB;
        std::cout << "Matrix subtraction of A and B:" << std::endl;
        subtractionResult.print();
        subtractionResult.exportToFile(outFile, "\nMatrix subtraction of A and B:");

        // Транспонирование матрицы A
        MatrixDense<double> transposeResult = matrixA.transpose();
        std::cout << "Transpose of matrix A:" << std::endl;
        transposeResult.print();
        transposeResult.exportToFile(outFile, "\nTranspose of matrix A:");

        outFile.close(); // Закрытие файла

        std::cout << "All matrices successfully generated in file matrices.txt" << std::endl; */

        /*
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Starting work with MatixBlock class" << std::endl;
        std::cout << "--------------------------------------" << std::endl;



        // Создаем блочную матрицу 3x4 с блоками 2x3
        BlockMatrix<double> blockMatrix(2, 3, 3, 4); // 2 строки, 3 столбца в блоке; 3 блока по строкам, 4 блока по столбцам

        // Заполняем блочную матрицу случайными значениями
        blockMatrix.fillRandom();

        // Выводим содержимое блочной матрицы
        std::cout << "Block Matrix:" << std::endl;
        blockMatrix.print();

        // Экспортируем в файл
        blockMatrix.exportToFile("block_matrix.txt");

        // Создаем новую блочную матрицу для импорта
        BlockMatrix<double> importedMatrix(0, 0, 0, 0); // Параметры не важны на этом этапе
        if (importedMatrix.importFromFile("block_matrix.txt")) {
            std::cout << "Block Matrix after import:" << std::endl;
            importedMatrix.print();
        } else {
            std::cerr << "Failed to import matrix." << std::endl;
        }

        // Умножаем на скаляр
        double scalar = 2.0;
        blockMatrix.scalarMultiply(scalar);
        std::cout << "After scalar multiplication by " << scalar << ":" << std::endl;
        blockMatrix.print();

        // Создаем другую блочную матрицу для поэлементного умножения
        BlockMatrix<double> blockMatrix2(2, 3, 3, 4);
        blockMatrix2.fillRandom();
        std::cout << "Second Block Matrix for element-wise multiplication:" << std::endl;
        blockMatrix2.print();

        // Поэлементное умножение
        BlockMatrix<double> elementWiseResult = blockMatrix.elementWiseMultiply(blockMatrix2);
        std::cout << "Element-wise multiplication result:" << std::endl;
        elementWiseResult.print();

        // Создаем другую блочную матрицу для матричного умножения
        BlockMatrix<double> blockMatrix3(3, 2, 4, 3);
        blockMatrix3.fillRandom();
        std::cout << "Third Block Matrix for matrix multiplication:" << std::endl;
        blockMatrix3.print();

        // Матричное умножение
        BlockMatrix<double> matrixMultiplyResult = blockMatrix * blockMatrix3;
        std::cout << "Matrix multiplication result:" << std::endl;
        matrixMultiplyResult.print();

        // Матричное сложение
        BlockMatrix<double> additionResult = blockMatrix + blockMatrix2;
        std::cout << "Addition result:" << std::endl;
        additionResult.print();

        // Матричное вычитание
        BlockMatrix<double> subtractionResult = blockMatrix - blockMatrix2;
        std::cout << "Subtraction result:" << std::endl;
        subtractionResult.print();

        // Транспонирование первой матрицы
        BlockMatrix<double> transposeResult = blockMatrix.transpose();
        std::cout << "Transpose of the first matrix:" << std::endl;
        transposeResult.print(); */


        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Starting work with MatixDiagonal class" << std::endl;
        std::cout << "--------------------------------------" << std::endl;


        // Создаем диагональную матрицу C размером 8
        MatrixDiagonal<double> matrixC(8);

        // Заполняем диагональные элементы случайными значениями с помощью нового метода
        matrixC.fillRandom();

        // Выводим диагональную матрицу C на экран в консоль
        std::cout << "Generated diagonal matrix C:" << std::endl;
        matrixC.print();

        //экспортируем диагональную матрицу в файл
        matrixC.exportToFile("Diagonal_Matrix_C.txt");
        std::cout << "Diagonal matrix C successfully exported to Diagonal_Matrix_C.txt" << std::endl;

        //импортируем диагональную матрицу из файла
        MatrixDiagonal<double> importedMatrix(8); //создаем новую матрицу
        if (importedMatrix.importFromFile("Diagonal_Matrix_C.txt")) {
            std::cout << "Imported diagonal matrix from file:" << std::endl;
            importedMatrix.print();
        } else {
            std::cerr << "Failed to import matrix." << std::endl;
        }



    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
