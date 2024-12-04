#include <iostream>
#include <cstdlib> // ��� ������� rand()
#include <ctime>   // ��� ������� time()
#include <fstream> // ��� std::ofstream
#include "Matrix.h"
#include "MatrixBlock.h"
#include "MatrixDiagonal.h"

// ������� ��� ���������� ������� ���������� ����������
template <typename T>
void fillMatrix(MatrixDense<T>& matrix) {
    for (unsigned i = 0; i < matrix.rows(); ++i) {
        for (unsigned j = 0; j < matrix.cols(); ++j) {
            matrix(i, j) = static_cast<T>(std::rand() % 100 + 1); // ��������� �������� �� 1 �� 100
        }
    }
}

int main() {
    try {
        // ������������� ���������� ��������� �����
        /*std::srand(static_cast<unsigned>(std::time(0)));

        // ������� ������� 3x3
        MatrixDense<double> matrixA(3, 3);
        MatrixDense<double> matrixB(3, 3);

        // ��������� ������� ���������� ����������
        fillMatrix(matrixA);
        fillMatrix(matrixB);

        // ������� ������� A � B � �������
        std::cout << "Generated matrix A:" << std::endl;
        matrixA.print();

        std::cout << "Generated matrix B:" << std::endl;
        matrixB.print();

        // ��������� ���� ��� ������
        std::ofstream outFile("matrices.txt");
        if (!outFile) {
            throw std::runtime_error("The file could not be opened for writing");
        }

        // ���������� ������� � ���� � �������������� ������ exportToFile
        matrixA.exportToFile(outFile, "Matrix A:");
        matrixB.exportToFile(outFile, "\nMatrix B:");

        // �������� ������� A �� ������
        double scalar = 2.5; // ������ �������
        MatrixDense<double> scaledMatrix = matrixA.scalarMultiply(scalar);

        // ������� �������������� ������� �� �����
        std::cout << "Scaled matrix A (multiplied by " << scalar << "):" << std::endl;
        scaledMatrix.print();

        // ���������� �������������� ������� � ����
        scaledMatrix.exportToFile(outFile, "\nScaled matrix A (multiplied by " + std::to_string(scalar) + "):");

        // ������������ ��������� ������ A � B
        MatrixDense<double> elementWiseResult = matrixA.elementWiseMultiply(matrixB);
        std::cout << "Element-wise multiplication of A and B:" << std::endl;
        elementWiseResult.print();
        elementWiseResult.exportToFile(outFile, "\nElement-wise multiplication of A and B:");

        // ��������� ��������� ������ A � B
        MatrixDense<double> matrixResult = matrixA * matrixB;
        std::cout << "Matrix multiplication of A and B:" << std::endl;
        matrixResult.print();
        matrixResult.exportToFile(outFile, "\nMatrix multiplication of A and B:");

        // ��������� ��������
        MatrixDense<double> additionResult = matrixA + matrixB;
        std::cout << "Matrix addition of A and B:" << std::endl;
        additionResult.print();
        additionResult.exportToFile(outFile, "\nMatrix addition of A and B:");

        // ��������� ���������
        MatrixDense<double> subtractionResult = matrixA - matrixB;
        std::cout << "Matrix subtraction of A and B:" << std::endl;
        subtractionResult.print();
        subtractionResult.exportToFile(outFile, "\nMatrix subtraction of A and B:");

        // ���������������� ������� A
        MatrixDense<double> transposeResult = matrixA.transpose();
        std::cout << "Transpose of matrix A:" << std::endl;
        transposeResult.print();
        transposeResult.exportToFile(outFile, "\nTranspose of matrix A:");

        outFile.close(); // �������� �����

        std::cout << "All matrices successfully generated in file matrices.txt" << std::endl; */

        /*
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Starting work with MatixBlock class" << std::endl;
        std::cout << "--------------------------------------" << std::endl;



        // ������� ������� ������� 3x4 � ������� 2x3
        BlockMatrix<double> blockMatrix(2, 3, 3, 4); // 2 ������, 3 ������� � �����; 3 ����� �� �������, 4 ����� �� ��������

        // ��������� ������� ������� ���������� ����������
        blockMatrix.fillRandom();

        // ������� ���������� ������� �������
        std::cout << "Block Matrix:" << std::endl;
        blockMatrix.print();

        // ������������ � ����
        blockMatrix.exportToFile("block_matrix.txt");

        // ������� ����� ������� ������� ��� �������
        BlockMatrix<double> importedMatrix(0, 0, 0, 0); // ��������� �� ����� �� ���� �����
        if (importedMatrix.importFromFile("block_matrix.txt")) {
            std::cout << "Block Matrix after import:" << std::endl;
            importedMatrix.print();
        } else {
            std::cerr << "Failed to import matrix." << std::endl;
        }

        // �������� �� ������
        double scalar = 2.0;
        blockMatrix.scalarMultiply(scalar);
        std::cout << "After scalar multiplication by " << scalar << ":" << std::endl;
        blockMatrix.print();

        // ������� ������ ������� ������� ��� ������������� ���������
        BlockMatrix<double> blockMatrix2(2, 3, 3, 4);
        blockMatrix2.fillRandom();
        std::cout << "Second Block Matrix for element-wise multiplication:" << std::endl;
        blockMatrix2.print();

        // ������������ ���������
        BlockMatrix<double> elementWiseResult = blockMatrix.elementWiseMultiply(blockMatrix2);
        std::cout << "Element-wise multiplication result:" << std::endl;
        elementWiseResult.print();

        // ������� ������ ������� ������� ��� ���������� ���������
        BlockMatrix<double> blockMatrix3(3, 2, 4, 3);
        blockMatrix3.fillRandom();
        std::cout << "Third Block Matrix for matrix multiplication:" << std::endl;
        blockMatrix3.print();

        // ��������� ���������
        BlockMatrix<double> matrixMultiplyResult = blockMatrix * blockMatrix3;
        std::cout << "Matrix multiplication result:" << std::endl;
        matrixMultiplyResult.print();

        // ��������� ��������
        BlockMatrix<double> additionResult = blockMatrix + blockMatrix2;
        std::cout << "Addition result:" << std::endl;
        additionResult.print();

        // ��������� ���������
        BlockMatrix<double> subtractionResult = blockMatrix - blockMatrix2;
        std::cout << "Subtraction result:" << std::endl;
        subtractionResult.print();

        // ���������������� ������ �������
        BlockMatrix<double> transposeResult = blockMatrix.transpose();
        std::cout << "Transpose of the first matrix:" << std::endl;
        transposeResult.print(); */


        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Starting work with MatixDiagonal class" << std::endl;
        std::cout << "--------------------------------------" << std::endl;


        // ������� ������������ ������� C �������� 8
        MatrixDiagonal<double> matrixC(8);

        // ��������� ������������ �������� ���������� ���������� � ������� ������ ������
        matrixC.fillRandom();

        // ������� ������������ ������� C �� ����� � �������
        std::cout << "Generated diagonal matrix C:" << std::endl;
        matrixC.print();

        //������������ ������������ ������� � ����
        matrixC.exportToFile("Diagonal_Matrix_C.txt");
        std::cout << "Diagonal matrix C successfully exported to Diagonal_Matrix_C.txt" << std::endl;

        //����������� ������������ ������� �� �����
        MatrixDiagonal<double> importedMatrix(8); //������� ����� �������
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
