#ifndef DIARY_H
#define DIARY_H

#include <string>

#include "Message.h"

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
    void copy_messages(); // Usado caso a capacidade de mensagens seja atingido
    void load_messages();
    void add(const std::string &message);
    void add(const Message message);
    void write();
    
};

#endif