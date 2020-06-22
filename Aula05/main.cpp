#include <iostream>
#include <string>
#include <fstream>

#include "usage.h"

int main(int argc, char* argv[]) {
    
    if (argc == 1){
        show_usage(argv[0]);
        return 1;
    }

    std::string action = argv[1];

    if (action != "add") {
        show_usage(argv[0]);
        return 1;
    }
    
    std::string message;
    if (argc == 2) {
        std::cout << "Informe a mensagem: " << std::endl;
        std::getline(std::cin, message);
    } else {
        message = argv[2];
    }

    std::ofstream arquivo_saida{"bd.txt", std::ios::app};
    if(!arquivo_saida.is_open()){
        std::cerr << "O arquivo não pode ser criado" << std::endl;
        return 1;
    }
    arquivo_saida << message << std::endl;
    arquivo_saida.close();
    std::cout << "Mensagem Adicionada" << std::endl;

    return 0;
}
