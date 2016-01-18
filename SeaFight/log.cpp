#include "log.h"

Log::Log() {
    fout.open("program.log");
}
Log::~Log() {
    if (fout.is_open()) fout.close();
}

bool Log::checkSring(std::string str) {
    if (str.find_first_not_of
    ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ_ ") 
    != std::string::npos) {
        return false;
    } else  return true;
}

bool Log::changeFilename(std::string str) {
    if (checkSring(str)) {
        if (fout.is_open()) fout.close();
        fout.open(std::string(str += ".log"));
        return true;
    } else return false;
}

void Log::printlog(std::string str1) {
    fout << str1.data();
}

void Log::printlog(std::string str1, std::string str2) {
    fout << (str1 += str2).data();
}

void Log::printlog(std::string str1, std::string str2, std::string str3) {
    fout << (str1 += str2 += str3).data();
}

void outlog(std::string str1) {
    static Log* log;
    log->get()->printlog(str1);
}

void outlog(std::string str1, std::string str2) {
    static Log* log;
    log->get()->printlog(str1, str2);
}
void outlog(std::string str1, std::string str2, std::string str3) {
    static Log* log;
    log->get()->printlog(str1, str2, str3);
}



