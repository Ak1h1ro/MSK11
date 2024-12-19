#include "vector.h"
#include "functions.h"
#include "timer.h"         // Подключаем класс Timer
#include "timing_logger.h" // Подключаем класс TimingLogger
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <omp.h>
#include <iomanip> // Для std::setprecision

void ExecutionOneThread(Vector<int>& vec1, Vector<int>& vec2, TimingLogger& logger) {
    std::cout << "ExecutionOneThread:\n";
    auto start = std::chrono::high_resolution_clock::now(); // Начало замера времени

    {
        Timer timer("findMinMax");
        auto [minMaxPair1, minMaxPair2] = findMinMax(vec1);
        auto [minValue, minIndex] = minMaxPair1;
        auto [maxValue, maxIndex] = minMaxPair2;
        std::cout << "Min: " << minValue << " at index " << minIndex << "\n";
        std::cout << "Max: " << maxValue << " at index " << maxIndex << "\n";
        long long duration = timer.getDuration();
        std::cout << "findMinMax took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("findMinMax", duration); // Логируем время
    }

    {
        Timer timer("calculateAverage");
        double avg = calculateAverage(vec1);
        std::cout << "Average: " << avg << "\n";
        long long duration = timer.getDuration();
        std::cout << "calculateAverage took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateAverage", duration); // Логируем время
    }

    {
        Timer timer("SumOfElements");
        double sum = SumOfElements(vec1);
        std::cout << "Sum: " << sum << "\n";
        long long duration = timer.getDuration();
        std::cout << "SumOfElements took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("SumOfElements", duration); // Логируем время
    }

    {
        Timer timer("calculateManhattanNorm");
        double manhattanNorm = calculateManhattanNorm(vec1);
        std::cout << "Manhattan Norm: " << manhattanNorm << "\n";
        long long duration = timer.getDuration();
        std::cout << "calculateManhattanNorm took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateManhattanNorm", duration); // Логируем время
    }

    {
        Timer timer("calculateEuclideanNorm");
        double euclideanNorm = calculateEuclideanNorm(vec1);
        std::cout << "Euclidean Norm: " << euclideanNorm << "\n";
        long long duration = timer.getDuration();
        std::cout << "calculateEuclideanNorm took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateEuclideanNorm", duration); // Логируем время
    }

    {
        Timer timer("dotProduct");
        double dotProd = dotProduct(vec1, vec2);
        std::cout << "Dot Product: " << dotProd << "\n";
        long long duration = timer.getDuration();
        std::cout << "dotProduct took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("dotProduct", duration); // Логируем время
    }
    auto end = std::chrono::high_resolution_clock::now(); // Конец замера времени
    std::chrono::duration<double> duration = end - start; // Вычисляем продолжительность
    std::cout << "Execution time (One Thread): " << duration.count() << " seconds\n";
}

void parallelExecutionThread(Vector<int>& vec1, Vector<int>& vec2, TimingLogger& logger) {
    std::cout << "parallelExecutionThread:\n";
    auto start = std::chrono::high_resolution_clock::now(); // Начало замера времени
    std::vector<std::thread> threads;

    threads.emplace_back([&]() {
        Timer timer("findMinMax");
        auto [minMaxPair1, minMaxPair2] = findMinMax(vec1);
        auto [minValue, minIndex] = minMaxPair1;
        auto [maxValue, maxIndex] = minMaxPair2;
        std::cout << "Min: " << minValue << " at index " << minIndex << "\n";
        std::cout << "Max: " << maxValue << " at index " << maxIndex << "\n";
        long long duration = timer.getDuration();
        std::cout << "findMinMax took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("findMinMax", duration); // Логируем время
    });

    threads.emplace_back([&]() {
        Timer timer("calculateAverage");
        double avg = calculateAverage(vec1);
        std::cout << "Average: " << avg << "\n";
        long long duration = timer.getDuration();
        std::cout << "calculateAverage took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateAverage", duration); // Логируем время
    });

    threads.emplace_back([&]() {
        Timer timer("SumOfElements");
        double sum = SumOfElements(vec1);
        std::cout << "Sum: " << sum << "\n";
        long long duration = timer.getDuration();
        std::cout << "SumOfElements took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("SumOfElements", duration); // Логируем время
    });

    threads.emplace_back([&]() {
        Timer timer("calculateManhattanNorm");
        double manhattanNorm = calculateManhattanNorm(vec1);
        std::cout << "Manhattan Norm: " << manhattanNorm << "\n";
        long long duration = timer.getDuration();
        std::cout << "calculateManhattanNorm took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateManhattanNorm", duration); // Логируем время
    });

    threads.emplace_back([&]() {
        Timer timer("calculateEuclideanNorm");
        double euclideanNorm = calculateEuclideanNorm(vec1);
        std::cout << "Euclidean Norm: " << euclideanNorm << "\n";
        long long duration = timer.getDuration();
        std::cout << "calculateEuclideanNorm took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateEuclideanNorm", duration); // Логируем время
    });

    threads.emplace_back([&]() {
        Timer timer("dotProduct");
        double dotProd = dotProduct(vec1, vec2);
        std::cout << "Dot Product: " << dotProd << "\n";
        long long duration = timer.getDuration();
        std::cout << "dotProduct took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("dotProduct", duration); // Логируем время
    });

    for (auto& th : threads) {
        th.join(); // Ожидаем завершения всех потоков
    }
    auto end = std::chrono::high_resolution_clock::now(); // Конец замера времени
    std::chrono::duration<double> duration = end - start; // Вычисляем продолжительность
    std::cout << "Execution time (parallelExecutionThread): " << duration.count() << " seconds\n";
}

void parallelExecutionOMP(Vector<int>& vec1, Vector<int>& vec2, TimingLogger& logger) {
    std::cout << "parallelExecutionOMP:\n";
    auto start = std::chrono::high_resolution_clock::now(); // Начало замера времени
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                Timer timer("findMinMax");
                auto [minMaxPair1, minMaxPair2] = findMinMax(vec1);
                auto [minValue, minIndex] = minMaxPair1;
                auto [maxValue, maxIndex] = minMaxPair2;
                std::cout << "Min: " << minValue << " at index " << minIndex << "\n";
                std::cout << "Max: " << maxValue << " at index " << maxIndex << "\n";
                long long duration = timer.getDuration();
                std::cout << "findMinMax took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
                logger.log("findMinMax", duration); // Логируем время
            }

            #pragma omp task
            {
                Timer timer("calculateAverage");
                double avg = calculateAverage(vec1);
                std::cout << "Average: " << avg << "\n";
                long long duration = timer.getDuration();
                std::cout << "calculateAverage took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
                logger.log("calculateAverage", duration); // Логируем время
            }

            #pragma omp task
            {
                Timer timer("SumOfElements");
                double sum = SumOfElements(vec1);
                std::cout << "Sum: " << sum << "\n";
                long long duration = timer.getDuration();
                std::cout << "SumOfElements took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
                logger.log("SumOfElements", duration); // Логируем время
            }

            #pragma omp task
            {
                Timer timer("calculateManhattanNorm");
                double manhattanNorm = calculateManhattanNorm(vec1);
                std::cout << "Manhattan Norm: " << manhattanNorm << "\n";
                long long duration = timer.getDuration();
        std::cout << "calculateManhattanNorm took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateManhattanNorm", duration); // Логируем время
            }

            #pragma omp task
            {
                Timer timer("calculateEuclideanNorm");
                double euclideanNorm = calculateEuclideanNorm(vec1);
                std::cout << "Euclidean Norm: " << euclideanNorm << "\n";
                long long duration = timer.getDuration();
        std::cout << "calculateEuclideanNorm took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("calculateEuclideanNorm", duration); // Логируем время
            }

            #pragma omp task
            {
                Timer timer("dotProduct");
                double dotProd = dotProduct(vec1, vec2);
                std::cout << "Dot Product: " << dotProd << "\n";
                long long duration = timer.getDuration();
        std::cout << "dotProduct took: " << std::fixed << std::setprecision(6) << duration / 1e6 << " seconds\n";
        logger.log("dotProduct", duration); // Логируем время
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now(); // Конец замера времени
    std::chrono::duration<double> duration = end - start; // Вычисляем продолжительность
    std::cout << "Execution time (parallelExecutionOMP): " << duration.count() << " seconds\n";
}

int main() {
  //  Vector<int> vec(10); // Создаем вектор целых чисел с размером 10
    Vector<int> vec1(100000000); // Создаем вектор целых чисел с размером 10
    Vector<int> vec2(100000000); // Создаем вектор целых чисел с размером 10

    // Создаем три объекта TimingLogger для разных логов
    TimingLogger loggerSequential("timing_sequential_log.txt");
    TimingLogger loggerThread("timing_thread_log.txt");
    TimingLogger loggerOMP("timing_omp_log.txt");


    try {
        // тут веткор с константными данными
        /*
        //Константные значения вектора vec
        vec.initializeWithConstant(8); // Инициализируем все элементы значением 8

        std::cout << "Size of vector: " << vec.getSize() << std::endl;
        for (size_t i = 0; i < vec.getSize(); ++i) {
            std::cout << "Element " << i << ": " << vec[i] << std::endl;
        }*/

        //Рандомные значения вектора vec1
         vec1.initializeWithRandomNumbers(-10, 10); // Инициализируем случайными числами от -10 до 10
        std::cout << "size of vector1: " << vec1.getSize() << std::endl;
        std::cout << "After inicialization random numbers vector1:" << std::endl;
        /*
        for (size_t i = 0; i < vec1.getSize(); ++i) {
            std::cout << "Element " << i << ": " << vec1[i] << std::endl;
        }*/

        //Рандомные значения вектора vec2
         vec2.initializeWithRandomNumbers(-10, 11); // Инициализируем случайными числами от -10 до 10
        std::cout << "size of vector2: " << vec2.getSize() << std::endl;
        std::cout << "After inicialization random numbers vector2:" << std::endl;
      /*  for (size_t i = 0; i < vec2.getSize(); ++i) {
            std::cout << "Element " << i << ": " << vec2[i] << std::endl;
        }

        */

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    std::cout<< "--------------------OneThread-------------------------------------"<<"\n" << std::endl;

        ExecutionOneThread(vec1,vec2,loggerSequential);


    std::cout<< "--------------------std::thread-------------------------------------"<<"\n" << std::endl;

        parallelExecutionThread(vec1, vec2,loggerThread);

    std::cout<< "-------------------------OpenMP--------------------------------------"<<"\n" << std::endl;

        parallelExecutionOMP(vec1, vec2,loggerOMP);


        /*

        // Экспорт данных в файл.
        vec1.exportToFile("output.txt");

        //Импорт данных из файла
        // Создаем новый объект для импорта.
        Vector<int> importedVec; // Создаем новый вектор
        importedVec.initializeWithConstant(0); // Инициализируем его перед импортом

        importedVec.importFromFile("output.txt");

        // Выводим импортированные данные.
        std::cout << "Imported data:" << std::endl;
        for (size_t i = 0; i < importedVec.getSize(); ++i) {
            std::cout << "Element " << i << ": " << importedVec[i] << std::endl;
        }

        */

        // Экспортируем данные в файлы
    loggerSequential.exportToFile();
    loggerThread.exportToFile();
    loggerOMP.exportToFile();

    return 0;
}
