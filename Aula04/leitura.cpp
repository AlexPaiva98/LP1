#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
    std::ifstream file("bd.txt");

    if (!file.is_open()) {
        std::cerr << "Arquivo não existente ou sem permissão de leitura" << std::endl;
        return 1;
    }   
    
    // eof end of file
    std::string message;
    int line_number = 0;

    while (!file.eof()) {
        ++line_number;
        std::getline(file, message);

        if (message.size() == 0) { //size
            continue;
        }

        std::cout << line_number << ". " <<message << std::endl;
    };

    file.close();

    return 0;
}