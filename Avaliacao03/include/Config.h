#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct Config {

    std::string path;
    std::string default_format;

    Config();

    void load();

};

#endif
