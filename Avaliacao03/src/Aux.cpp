#include <ctime>

#include "../include/Aux.h"

std::string format_current_date(const std::string& format) {
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

std::string get_current_date() {
    return format_current_date("%d/%m/%Y");
}

std::string get_current_time() {
    return format_current_date("%H:%M:%S");
}

std::string replace_all(std::string string_update, const std::string &from, const std::string &to) {
    size_t i = 0;
    while ((i = string_update.find(from, i)) != std::string::npos) {
        string_update.replace(i, from.length(), to);
        i += to.length();
    }
    return string_update;
}
