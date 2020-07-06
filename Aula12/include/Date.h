#ifndef DATE_H
#define DATE_H

#include <string>

struct Date {

    // Construtores
    Date();
    Date(unsigned year, unsigned month, unsigned day);

    // Atributos
    unsigned year;
    unsigned month;
    unsigned day;

    // Métodos
    void set_from_string(const std::string &date);
    std::string to_string();

};

#endif
