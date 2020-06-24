#include <iostream>

#include "../include/Diary.h"
#include "../include/Message.h"

Diary::Diary(const std::string& filename): 
    filename(filename), 
    messages_capacity(10),
    messages_size(0),
    messages(nullptr)
    {
        messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message) {
    Date date(2020, 6, 24); // Futuramente obter isso automaticamente
    Time time(9, 40, 0); // Futuramente obter isso automaticamente
    Message new_message (message, date, time);
    messages[messages_size] = new_message;
    messages_size++;
}

void Diary::write() {
    // gravar as mensagens no disco
}

void Diary::list() {
    for(int i = 0; i < messages_size; i++) {
        std::cout << messages[i].content << std::endl;
    }
}
