#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class CpuSpec {
public:
    std::string model;
    int cores;
    float frequency;
    int threads;
    int cacheSize;
    std::string architecture;

    void print() const;  // Изменено на const
    void exportData(std::ofstream& file) const;  // Изменено на ofstream
    void importData(std::ifstream& file);  // Изменено на ifstream
};

class GpuSpec {
public:
    int memory;
    float coreClock;
    std::string memoryType;
    int memorySize;
    std::string model;
    int shaderCores;
    float tdp;

    void print() const;  // Изменено на const
    void exportData(std::ofstream& file) const;  // Изменено на ofstream
    void importData(std::ifstream& file);  // Изменено на ifstream
};

class RamSpec {
public:
    int capacity; // in GB
    double speed; // in MHz

    void print() const;  // Изменено на const
    void exportData(std::ofstream& file) const;  // Изменено на ofstream
    void importData(std::ifstream& file);  // Изменено на ifstream
};

class LanSpec {
public:
    int bandwidth; // in Mbps

    void print() const;  // Изменено на const
    void exportData(std::ofstream& file) const;  // Изменено на ofstream
    void importData(std::ifstream& file);  // Изменено на ifstream
};

class ClusterNode : public CpuSpec, public GpuSpec, public RamSpec, public LanSpec {
public:
    int id_node;

    void print() const;  // Изменено на const
    void exportData(std::ofstream& file) const;  // Изменено на ofstream
    void importData(std::ifstream& file);  // Изменено на ifstream
};

class Cluster {

public:
    std::vector<ClusterNode> nodes;
    std::string name;
    std::string status;
    void addNode(const ClusterNode& node);
    void removeNode(int id);
    size_t nodeCount() const;
    void print() const;
};

#endif // CLUSTER_H
