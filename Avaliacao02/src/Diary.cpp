#include <iostream>
#include <fstream>

#include "../include/Diary.h"
#include "../include/Aux.h"
#include "../include/Date.h"

Diary::Diary(const std::string& filename): 
    filename(filename), 
    messages(nullptr), 
    messages_size(0), 
    messages_capacity(10) {
        messages = new Message[messages_capacity];
        load_messages();
}

Diary::~Diary() {
    delete[] messages;
}

void Diary::copy_messages() {

    messages_capacity *= 2;
    Message* new_messages = new Message[messages_capacity];
    for (size_t i = 0; i < messages_size; i++) {
        new_messages[i] = messages[i];
    }

    delete[] messages;

    messages = new_messages;

}

void Diary::load_messages() {

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Arquivo não existente ou sem permissão de leitura" << std::endl;
        return;
    }

    Message object_message;
    Date featured_date;   
    
    std::string message;
    std::string hashtag = "#";

    while (!file.eof()) {
        std::getline(file, message);

        if (message.size() == 0) {
            continue;
        }

        if(message[0] == hashtag[0]) {
            message.erase(0, 1);
            featured_date.set_from_string(message);
            continue;
        }

        // Date
        object_message.date = featured_date;
        
        // Time
        message.erase(0, 2);            
        object_message.time.set_from_string(message);
        
        // Content
        message.erase(0, 9);
        object_message.content = message;

        add(object_message);
 
    };

    file.close();
}

void Diary::add(const std::string& message) {
    
    if (messages_size == messages_capacity) {
        copy_messages();
    }

    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    
    messages[messages_size] = m;
    messages_size++;

}

void Diary::add(const Message message) {

    if (messages_size == messages_capacity) {
        copy_messages();
    }

    messages[messages_size] = message;
    messages_size++;

}

void Diary::write() {

    std::ofstream file{filename};
    
    if(!file.is_open()){
        std::cerr << "O arquivo não pode ser criado" << std::endl;
        return;
    }

    Date date;    
    for (size_t i = 0; i < messages_size; i++) {
       
        if(
            date.day != messages[i].date.day
            || date.month != messages[i].date.month
            || date.year != messages[i].date.year
        ) {

            date.day = messages[i].date.day;
            date.month = messages[i].date.month;
            date.year = messages[i].date.year;

            file << std::endl << "# " << messages[i].date.to_string() << std::endl << std::endl;

        } 

        file << "- " << messages[i].time.to_string() << " " << messages[i].content  << std::endl;

    }

    file.close();

}
