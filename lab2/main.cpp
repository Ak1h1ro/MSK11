#include <cstdlib> // ��� ������� rand()
#include <ctime>   // ��� ������� time()
#include <fstream> // ��� std::ofstream
//#include "Matrix.h"
//#include "MatrixBlock.h"
#include <iostream>

#include <iostream>
#include "MatrixDiagonal.h"

int main() {
    try {

         /*  // ������� ������� 3x3
        MatrixDense<double> matrixA(3, 3);
        MatrixDense<double> matrixB(3, 3);

        // ��������� ������� ���������� ����������
        matrixA.fillRandom();
        matrixB.fillRandom();

        // ������� ������� A � B � �������
        std::cout << "Generated matrix A:" << std::endl;
        matrixA.print();

        std::cout << "Generated matrix B:" << std::endl;
        matrixB.print();

        // ������������ ������� A � ����
        matrixA.exportToFile("Matrix_A.txt");

        std::cout << "Matrix A successfully exported to file: Matrix_A.txt" << std::endl;

        // ������� ����� ������� ��� �������
        MatrixDense<double> matrixC(3, 3);

        if (matrixC.importFromFile("Matrix_A.txt")) {
            std::cout << "Matrix C successfully imported from file: Matrix_A.txt" << std::endl;
            matrixC.print();  // ������� ��������������� ������� B �� �����
        } else {
            std::cerr << "Failed to import matrix." << std::endl;
        }

        // �������� ������� A �� ������
        double scalar = 2.5; // ������ �������
        MatrixDense<double> scaledMatrix = matrixA.scalarMultiply(scalar);

        // ������� �������������� ������� �� �����
        std::cout << "Scaled matrix A (multiplied by " << scalar << "):" << std::endl;
        scaledMatrix.print();

        // ������������ ��������� ������ A � B
        MatrixDense<double> elementWiseResult = matrixA.elementWiseMultiply(matrixB);
        std::cout << "Element-wise multiplication of A and B:" << std::endl;
        elementWiseResult.print();

        // ��������� ��������� ������ A � B
        MatrixDense<double> matrixResult = matrixA * matrixB;
        std::cout << "Matrix multiplication of A and B:" << std::endl;
        matrixResult.print();

        // ��������� ��������
        MatrixDense<double> additionResult = matrixA + matrixB;
        std::cout << "Matrix addition of A and B:" << std::endl;
        additionResult.print();

        // ��������� ���������
        MatrixDense<double> subtractionResult = matrixA - matrixB;
        std::cout << "Matrix subtraction of A and B:" << std::endl;
        subtractionResult.print();

        // ���������������� ������� A
        MatrixDense<double> transposeResult = matrixA.transpose();
        std::cout << "Transpose of matrix A:" << std::endl;
        transposeResult.print(); */

        /*
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Starting work with MatixBlock class" << std::endl;
        std::cout << "--------------------------------------" << std::endl;



        // ������� ������� ������� 3x4 � ������� 2x3
        BlockMatrix<double> blockMatrix(2, 3, 3, 4); // 2 ������, 3 ������� � �����; 3 ����� �� �������, 4 ����� �� ��������

        // ��������� ������� ������� ���������� ����������
        blockMatrix.fillRandom();

        // ������ � ��������
        try {
            int value = blockMatrix(1, 1, 0, 0); // ������ � �������� � ����� (1, 1) �� ������� (0, 0)
            std::cout << "Element at block (1, 1), position (0, 0): " << value << std::endl;

            // �������� �������
            blockMatrix(1, 1, 0, 0) = 42;
            std::cout << "New value at block (1, 1), position (0, 0): " << blockMatrix(1, 1, 0, 0) << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // ������� ���������� ������� �������
        std::cout << "Block Matrix:" << std::endl;
        blockMatrix.print();

        // ������������ � ����
        blockMatrix.exportToFile("block_matrix.txt");

        // ������� ����� ������� ������� ��� �������
        BlockMatrix<double> importedMatrix(2, 3, 3, 4); // ��������� ������ ��������� � �������� ��������
        if (importedMatrix.importFromFile("block_matrix.txt")) {
            std::cout << "Block Matrix after import:" << std::endl;
            importedMatrix.print();
        } else {
            std::cerr << "Failed to import matrix." << std::endl;
        }

        // �������� �� ������
        double scalar1 = 2.0;
        blockMatrix.scalarMultiply(scalar1);
        std::cout << "After scalar multiplication by " << scalar1 << ":" << std::endl;
        blockMatrix.print();

        // ������� ������ ������� ������� ��� ������������� ���������
        BlockMatrix<double> blockMatrix2(2, 3, 3, 4);
        blockMatrix2.fillRandom();
        std::cout << "Second Block Matrix for element-wise multiplication:" << std::endl;
        blockMatrix2.print();

        // ������������ ���������
        BlockMatrix<double> elementWiseResultBlock = blockMatrix.elementWiseMultiply(blockMatrix2);
        std::cout << "Element-wise multiplication result:" << std::endl;
        elementWiseResultBlock.print();

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
        BlockMatrix<double> additionResultBlock = blockMatrix + blockMatrix2;
        std::cout << "Addition result:" << std::endl;
        additionResultBlock.print();

        // ��������� ���������
        BlockMatrix<double> subtractionResultBlock = blockMatrix - blockMatrix2;
        std::cout << "Subtraction result:" << std::endl;
        subtractionResultBlock.print();

        // ���������������� ������ �������
        BlockMatrix<double> transposeResultBlock = blockMatrix.transpose();
        std::cout << "Transpose of the first matrix:" << std::endl;
        transposeResultBlock.print(); */


        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Starting work with MatixDiagonal class" << std::endl;
        std::cout << "--------------------------------------" << std::endl;


        int size = 5; // ������ �������

        // ������ � ������ �������
        MatrixDiagonal<int> intMatrix(size);
        std::cout << "Integer matrix:" << std::endl;
        intMatrix.print();

        intMatrix.addLowerDiagonal(2);
        intMatrix.fillLowerDiagonalRandom(2);

        std::cout << "\nThe matrix after adding the lower diagonal with an offset of -2:" << std::endl;
        intMatrix.print();

        intMatrix.addUpperDiagonal(3);
        intMatrix.fillUpperDiagonalRandom(3);
        std::cout << "\nThe matrix after adding the lower diagonal with an offset of +3:" << std::endl;
        intMatrix.print();

        /*// ������ � ������� � ��������� �������
        MatrixDiagonal<double> doubleMatrix(size);
        std::cout << "\nFloat matrix:" << std::endl;
        doubleMatrix.print();

        doubleMatrix.addLowerDiagonal(2);
        doubleMatrix.fillLowerDiagonalRandom(2);

        std::cout << "\nThe matrix after adding the lower diagonal with an offset of -2:" << std::endl;
        doubleMatrix.print(); */

        //������ � ����
        intMatrix.exportToFile("diagonal_matrix.txt");

        //������� �� �����
        MatrixDiagonal<int> importedMatrix(0); // ������� ������ �������
        importedMatrix.importFromFile("diagonal_matrix.txt");
        std::cout << "\nThe matrix after import:" << std::endl;
        importedMatrix.print();

        MatrixDiagonal<int> matrixB(4);
        matrixB.addLowerDiagonal(2);
        matrixB.fillLowerDiagonalRandom(2);
        std::cout << "Integer matrix B:" << std::endl;
        matrixB.print();

        MatrixDiagonal<int> result = intMatrix.kroneckerMultiplication(matrixB);
        // ������ � ��������� ����� ��������()
        int value = result(0, 0);
        std::cout << "value(0,0) = " << value << std::endl;
        unsigned sizeOfResult = result.size();
        std::cout << "size Of Result = " << sizeOfResult << std::endl;
        result.print();

        MatrixDiagonal<int> scaledMatrix = matrixB.scalarMultiply(2);
        std::cout << "\nThe matrix B after scalar multiplication by 2:" << std::endl;
        scaledMatrix.print();

        //�������� ������� � ��� ��������� �� ������� �
        MatrixDiagonal<int> matrixC(4);
        matrixC.addLowerDiagonal(2);
        matrixC.fillLowerDiagonalRandom(2);

        std::cout << "Integer matrix C:" << std::endl;
        matrixC.print();

        MatrixDiagonal<int> elementWiseResult = matrixC.elementWiseMultiply(matrixB);
        std::cout << "\nThe result of element wise multiplication:" << std::endl;
        elementWiseResult.print();

        MatrixDiagonal<int> multipliedResult = matrixC * matrixB;
        std::cout << "\nThe result of matrix multiplication:" << std::endl;
        multipliedResult.print();


    } catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }

    return 0;
}

