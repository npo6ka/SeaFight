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

void Log::printlog(std::string str) {
    fout << str.data();
}

void outlog(std::string str) {
    static Log* log;
    log->get()->printlog(str);
}



