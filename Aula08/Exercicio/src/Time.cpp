#include "../include/Time.h"

Time::Time(): hour(0), minute(0), second(0) {
    
}

Time::Time(unsigned hour, unsigned minute, unsigned second): hour(hour), minute(minute), second(second) {
    
}

void Time::set_from_string(const std::string &time) {
    std::stringstream stream(time);
    
    char discard; // Utilizado para remover o :

    stream >> hour;
    stream >> discard;
    stream >> minute;
    stream >> discard;
    stream >> second;

}
