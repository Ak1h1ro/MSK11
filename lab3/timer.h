#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

class Timer {
private:
    std::string operationName; // Название операции
    std::chrono::high_resolution_clock::time_point startTime; // Время начала

public:
    Timer(const std::string& name) : operationName(name) {
        startTime = std::chrono::high_resolution_clock::now(); // Начало отсчета
    }

    ~Timer() {
        // Деструктор не делает ничего, время логируем в функции
    }

    long long getDuration() const {
        auto endTime = std::chrono::high_resolution_clock::now(); // Конец отсчета
        return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count(); // Возвращаем продолжительность
    }
};

#endif // TIMER_H
