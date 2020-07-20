#ifndef CLASS_CLIENTE_PF
#define CLASS_CLIENTE_PF

#include <string>

#include "Cliente.hpp"

class ClientePF: public Cliente {
    
    private:

        std::string cpf;
        std::string nome;
        static int quantidade;

    public:
    
        ClientePF(std::string nome, std::string cpf, Endereco &endereco);
        ClientePF();
        ~ClientePF();

        std::string getCPF();
        void setCPF(std::string cpf);

        std::string getNome();
        void setNome(std::string nome);

        int getQuantidade();

};

#endif
