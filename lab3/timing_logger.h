#ifndef TIMING_LOGGER_H
#define TIMING_LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class TimingLogger {
private:
    std::map<std::string, long long> timings; // Словарь для хранения времён выполнения
    std::string filename; // Имя файла для записи логов

public:
    TimingLogger(const std::string& file) : filename(file) {}

    void log(const std::string& operationName, long long duration) {
        timings[operationName] += duration; // Добавляем время к существующему
    }

    void exportToFile() const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& entry : timings) {
                outFile << entry.first << ": " << entry.second << " microseconds\n"; // Запись в файл
            }
            outFile.close();
        } else {
            std::cerr << "Unable to open file for logging!" << std::endl;
        }
    }
};

#endif // TIMING_LOGGER_H
