#include "../include/Date.h"

Date::Date(): year(0), month(0), day(0) {

}

Date::Date(unsigned year, unsigned month, unsigned day): year(year), month(month), day(day) {

}

void Date::set_from_string(const std::string &date) {
    std::stringstream stream(date);
    
    char discard; // Utilizado para remover o /

    stream >> day;
    stream >> discard;
    stream >> month;
    stream >> discard;
    stream >> year;

}
