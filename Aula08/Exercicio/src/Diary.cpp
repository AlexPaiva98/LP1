#include "../include/Diary.h"

Diary::Diary(const std::string& filename): 
    filename(filename), 
    messages(nullptr), 
    messages_size(0), 
    messages_capacity(10) {
        messages = new Message[messages_capacity];
}

Diary::~Diary() {
    delete[] messages;
}

void Diary::add(const std::string& message) {
    
    if (messages_size == messages_capacity) {
        return;
    }

    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    messages[messages_size] = m;
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
