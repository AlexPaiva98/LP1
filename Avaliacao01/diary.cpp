#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

// Funções relacionadas a grandeza de tempo
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

// Funções auxiliares
int isExistsDate(const std::string& date) {
    
    std::ifstream file("bd.md");
    if (!file.is_open()) {
        std::cerr << "Arquivo não existente ou sem permissão de leitura" << std::endl;
        return -1;
    }   
    
    std::string message;
    while (!file.eof()) {
        std::getline(file, message);

        if (message.size() == 0) {
            continue;
        }

        if (date == message) {
            return 1;
        }

    };

    file.close();

    return 0;
}

void show_usage(const std::string &prog_name) {
    
    std::cout << "1. Uso: " << prog_name << " add <mensagem>" << std::endl;
    std::cout << "2. Uso: " << prog_name << " list" << std::endl;

}

// Funções relacionadas aos requisitos do programa
int add(const std::string &message) {

    std::ofstream file{"bd.md", std::ios::app};
    if(!file.is_open()){
        std::cerr << "O arquivo não pode ser criado" << std::endl;
        return -1;
    }

    std::string date = "# " + get_current_date();
    std::string time = get_current_time();
    int exists = isExistsDate(date);

    if (exists == 1) {
        file << "- " << time << " " << message << std::endl; // Adiciona o registro
    } else if (exists == 0) {
        file << std::endl << date << std::endl << std::endl; // Adiciona o título entre linhas
        file << "- " << time << " " << message << std::endl; // Adiciona o registro
    } else {
        return exists;
    }
    
    file.close();

    std::cout << "Mensagem Adicionada" << std::endl;

    return 0;

}

int list() {

    std::ifstream file("bd.md");

    if (!file.is_open()) {
        std::cerr << "Arquivo não existente ou sem permissão de leitura" << std::endl;
        return -1;
    }   
    
    std::string message;
    std::string hashtag = "#";

    while (!file.eof()) {
        std::getline(file, message);

        if (message.size() == 0 || message[0] == hashtag[0]) {
            continue;
        }
        
        message.erase(0, 11);
        
        std::cout << "- " << message << std::endl;

    };

    file.close();

    return 0;

}

// Menu de direcionamento
int action(int argc, char* argv[]) {

    std::string action = argv[1];

    if (action == "add") {
        std::string message;
        if (argc == 2) {
            std::cout << "Informe a mensagem: " << std::endl;
            std::getline(std::cin, message);
        } else {
            message = argv[2];
        }
        return add(message);
    }

    if (action == "list") {
        return list();
    }

    show_usage(argv[0]);
    return -1;

}

int main(int argc, char* argv[]) {
    
    if (argc == 1){
        show_usage(argv[0]);
        return -1;
    }

    return action(argc, argv);

}

// By Alex Sandro de Paiva
