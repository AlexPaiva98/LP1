#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>

struct Diary {

    std::string filename;
    size_t messages_capacity;
    size_t messages_size;
    Message* messages;

    Diary(const std::string &filename);

    void add(const std::string &message);
    void write();
    void list();

};

#endif