#include <iostream>
#include <fstream>

#include "../include/Diary.h"
#include "../include/Aux.h"
#include "../include/Date.h"

Diary::Diary(const std::string& filename): 
    filename(filename) {
        load_messages();
}

void Diary::load_messages() {

    std::ifstream file(filename);
    if (!file.is_open()) {
        // std::cerr << "Arquivo não existente ou sem permissão de leitura" << std::endl;
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
    
    Message object_message;
    object_message.content = message;
    object_message.date.set_from_string(get_current_date());
    object_message.time.set_from_string(get_current_time());
    
    add(object_message);

}

void Diary::add(const Message object_message) {
    
    messages.push_back(object_message);

}

void Diary::write() {

    std::ofstream file{filename};
    
    if(!file.is_open()){
        // std::cerr << "O arquivo não pode ser criado" << std::endl;
        return;
    }

    Date date;    
    for (auto i: messages) {
       
        if(
            date.day != i.date.day
            || date.month != i.date.month
            || date.year != i.date.year
        ) {

            date.day = i.date.day;
            date.month = i.date.month;
            date.year = i.date.year;

            file << std::endl << "# " << i.date.to_string() << std::endl << std::endl;

        } 

        file << "- " << i.time.to_string() << " " << i.content  << std::endl;

    }

    file.close();

}

std::vector<Message*> Diary::search(std::string what) {

    std::vector<Message*> filtered_messages;
    for (auto& i: messages) {
        size_t found = i.content.find(what);
        if (found != std::string::npos) {
            filtered_messages.push_back(&i);
        }
    }

    return filtered_messages;

}
