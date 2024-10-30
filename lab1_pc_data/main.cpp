#include "cluster.h"
#include <iostream>
#include <fstream>

int main() {
    // Создание экземпляров классов спецификаций
    CpuSpec cpu;
    cpu.model = "Intel Core i9";
    cpu.cores = 8;
    cpu.frequency = 3.6;
    cpu.threads = 16;
    cpu.cacheSize = 16;
    cpu.architecture = "x86_64";

    GpuSpec gpu;
    gpu.model = "NVIDIA GeForce RTX 3080";
    gpu.memorySize = 10; // В ГБ
    gpu.coreClock = 1.44;
    gpu.memoryType = "GDDR6X";
    gpu.shaderCores = 8704;
    gpu.tdp = 320;

    RamSpec ram;
    ram.capacity = 32; // В ГБ
    ram.speed = 3200; // В МГц

    LanSpec lan;
    lan.bandwidth = 1000; // В Мбит/с

    // Создание узла кластера
    ClusterNode node;
    node.id_node = 1;

    // Заполнение полей узла напрямую
    node.CpuSpec::model = cpu.model;
    node.CpuSpec::cores = cpu.cores;
    node.CpuSpec::frequency = cpu.frequency;
    node.CpuSpec::threads = cpu.threads;
    node.CpuSpec::cacheSize = cpu.cacheSize;
    node.CpuSpec::architecture = cpu.architecture;

    node.GpuSpec::model = gpu.model;
    node.GpuSpec::memorySize = gpu.memorySize;
    node.GpuSpec::coreClock = gpu.coreClock;
    node.GpuSpec::memoryType = gpu.memoryType;
    node.GpuSpec::shaderCores = gpu.shaderCores;
    node.GpuSpec::tdp = gpu.tdp;

    node.RamSpec::capacity = ram.capacity;
    node.RamSpec::speed = ram.speed;

    node.LanSpec::bandwidth = lan.bandwidth;

    // Печать информации о узле
    std::cout << "Cluster Node Information:\n";
    node.print();

    // Экспорт данных узла в файл
    std::ofstream outFile("node1.txt");
    node.exportData(outFile);
    outFile.close();

    // Создание кластера и добавление узла
    Cluster cluster;
    cluster.name = "MyCluster"; // Установка имени кластера
    cluster.status = "Active"; // Установка статуса кластера
    cluster.addNode(node);

    // Печать информации о кластере
    std::cout << "\nCluster Information:\n";
    cluster.print();

    // Импорт данных из файла
    ClusterNode importedNode;
    std::ifstream inFile("node1.txt");
    importedNode.importData(inFile);
    inFile.close();

    // Печать информации о импортированном узле
    std::cout << "\nImported Node Information:\n";
    importedNode.print();

    return 0;
}
