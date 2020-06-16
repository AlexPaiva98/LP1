#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    if(argc == 1) {
        
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;

    } else if (argc == 2){

        std::string parametroEsperado ("add");
        std::string parametroRecebido (argv[1]);

        if (parametroEsperado.compare(parametroRecebido) == 0) {
            std::string mensagem;
            std::getline(std::cin, mensagem);
            std::cout << "Mensagem Adicionada" << std::endl;
        } else {
            std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
            return -1;
        }

    } else if (argc == 3) {

        std::string parametroEsperado ("add");
        std::string parametroRecebido (argv[1]);

        if (parametroEsperado.compare(parametroRecebido) == 0) {
            std::cout << "Mensagem Adicionada" << std::endl;
        } else {
            std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
            return -1;
        }

    } else {
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }
    return 0;
}

// By Alex Sandro de Paiva