#ifndef TIME_H
#define TIME_H

#include <string>

struct Time {

    // Construtores
    Time();
    Time(unsigned hour, unsigned minute, unsigned second);

    // Atributos
    unsigned hour;
    unsigned minute;
    unsigned second;

    // Métodos
    void set_from_string(const std::string &time);

};

#endif
