#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

#include "Date.h"
#include "Time.h"

struct Message {
    
    // Construtores
    Message();
    Message(std::string content, Date date, Time time);

    // Atributos
    std::string content;
    Date date;
    Time time;
    
};

#endif