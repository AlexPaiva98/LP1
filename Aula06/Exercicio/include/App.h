#ifndef APP_H
#define APP_H

#include <string>

#include "Diary.h"

struct App {

    Diary diary;
    
    // Construtor
    App(const std::string &filename);
    
    int run(int argc, char* argv[]);
    int show_usage();
    void add();
    void add(const std::string &message);
    void list_messages();

};

#endif