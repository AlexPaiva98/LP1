#ifndef CLASS_CLIENTE
#define CLASS_CLIENTE

#include <string>

class Cliente {
    
    public:
        std::string cpf;
        std::string nome;
    
    static int quantidade;

    Cliente(std::string nome, std::string cpf);
    Cliente();
    ~Cliente();

};

#endif
