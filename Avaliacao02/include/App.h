#ifndef APP_H
#define APP_H

#include <string>

#include "Diary.h"

struct App {
    
    // Construtor
    App(const std::string &filename);
    
    // Atributo
    Diary diary;

    // Métodos
    int run(int argc, char* argv[]);
    int show_usage(const std::string &prog_name);
    void add();
    void add(const std::string &message);
    void list_messages();

};

#endif