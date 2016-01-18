#pragma once
#include <iostream>
#include <fstream>

class Log {
    std::ofstream fout;
    Log();
    ~Log();
    bool checkSring(std::string);
public:
    bool changeFilename(std::string);
    static Log *get() {
        static Log log;
        return &log;
    }
    void printlog(std::string);
    void printlog(std::string, std::string);
    void printlog(std::string, std::string, std::string);
};

void outlog(std::string);
void outlog(std::string, std::string);
void outlog(std::string, std::string, std::string);
