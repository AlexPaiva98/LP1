#include <iostream>
#include <fstream>

#include "../include/Config.h"

Config::Config() {
    load();
}

void Config::load() {

    std::ifstream file_load("diary.config");
    if (!file_load.is_open()) {

        file_load.close();

        std::ofstream file_write{"diary.config", std::ios::app};
        if(!file_write.is_open()){
            std::cerr << "O arquivo não pode ser criado" << std::endl;
            return;
        }

        path = "diary.md";
        default_format="%d %t: %m";

        file_write << "path=" << path << std::endl;
        file_write << "default_format=" << default_format << std::endl;

        file_write.close();

        return;
    
    }

    std::string message;

    while (!file_load.eof()) {
        std::getline(file_load, message);

        if (message.size() == 0) {
            continue;
        }

        size_t found = message.find("path=");

        if (found != std::string::npos) {
            message.erase(0, 5);
            path = message;
            continue;
        }

        found = message.find("default_format=");

        if (found != std::string::npos) {
            message.erase(0, 15);
            default_format = message;
        }

    }

    file_load.close();

}