#ifndef ATV05_DIARY_H
#define ATV05_DIARY_H

#include <string>

#include "Message.h"

struct Diary {

    std::string title;
    std::string fileName;

    bool insert(const Message &message);
    bool remove(const Message &message);
    bool update(const Message &message);
    void list();

    void show_usage();

};

#endif