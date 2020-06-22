#ifndef ATV05_MESSAGE_H
#define ATV05_MESSAGE_H

#include <string>

#include "DateTime.h"

struct Message {
    Date date;
    Time time;
    std::string content;

    bool compare_dates(const Message &other_message);
};

#endif
