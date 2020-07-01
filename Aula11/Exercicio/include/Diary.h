#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <vector>

#include "Message.h"

struct Diary {

    // Construtor
    Diary(const std::string &filename);

    // Atributos
    std::string filename;
    std::vector<Message> messages; 

    // Métodos
    void load_messages();
    void add(const std::string &message);
    void add(const Message message);
    void write();
    std::vector<Message*> search(std::string what); // std::vector<Message*> // vetor de ponteiros de mensagens
    
};

#endif