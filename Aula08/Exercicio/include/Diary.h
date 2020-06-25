#ifndef DIARY_H
#define DIARY_H

#include <iostream>
#include <string>

#include "Message.h"
#include "Aux.h"

struct Diary {

    // Construtor
    Diary(const std::string &filename);

    // Destrutor | chamado automaticamente no fim da execução
    ~Diary();

    // Atributos
    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    // Métodos
    void add(const std::string &message);
    void write();
    void list();

};

#endif