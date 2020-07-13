#ifndef APP_H
#define APP_H

#include <string>

#include "Diary.h"
#include "Config.h"

struct App {
    
    // Construtor
    App(const Config* config_default);
    
    // Atributos
    Diary diary;
    std::string default_format;

    // Métodos
    int run(int argc, char* argv[]);
    int show_usage(const std::string &prog_name);
    void interactive();
    void add();
    void add(const std::string &message);
    void list();
    void list(const std::string &message);
    void search();
    void search(const std::string &what);
};

#endif