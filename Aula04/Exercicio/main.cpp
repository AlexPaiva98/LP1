#include <iostream>
#include <string>
#include <fstream>

void show_usage(const std::string &prog_name) {
    
    std::cout << "1. Uso: " << prog_name << " add <mensagem>" << std::endl;
    std::cout << "2. Uso: " << prog_name << " list" << std::endl;

}

int add(int argc, char* argv[]) {

    std::string message;

    if (argc == 2) {
        std::cout << "Informe a mensagem: " << std::endl;
        std::getline(std::cin, message);
    } else {
        message = argv[2];
    }

    std::ofstream file{"bd.txt", std::ios::app};
    if(!file.is_open()){
        std::cerr << "O arquivo não pode ser criado" << std::endl;
        return 1;
    }

    file << message << std::endl;

    file.close();

    std::cout << "Mensagem Adicionada" << std::endl;

    return 0;

}

int list() {

    std::ifstream file("bd.txt");

    if (!file.is_open()) {
        std::cerr << "Arquivo não existente ou sem permissão de leitura" << std::endl;
        return 1;
    }   
    
    std::string message;
    int line_number = 0;
    while (!file.eof()) {
        ++line_number;
        std::getline(file, message);

        if (message.size() == 0) {
            continue;
        }

        std::cout << line_number << ". " <<message << std::endl;
    };

    file.close();

    return 0;

}

int action(int argc, char* argv[]) {

    std::string action = argv[1];

    if (action == "add") {
        return add(argc, argv);
    }

    if (action == "list") {
        return list();
    }

    show_usage(argv[0]);
    return 1;

}

int main(int argc, char* argv[]) {
    
    if (argc == 1){
        show_usage(argv[0]);
        return 1;
    }

    return action(argc, argv);

}

// By Alex Sandro de Paiva