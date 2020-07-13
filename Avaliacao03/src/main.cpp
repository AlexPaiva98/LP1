#include <iostream>

#include "../include/Config.h"
#include "../include/App.h"

int main(int argc, char* argv[]){

    Config config;

    App aplicativo(&config);

    return aplicativo.run(argc, argv);

}
