#ifndef CLASS_CLIENTE
#define CLASS_CLIENTE

#include <string>

class Cliente {
    
    private:
        std::string cpf;
        std::string nome;
        static int quantidade;

    public:
        Cliente(std::string nome, std::string cpf);
        Cliente();
        ~Cliente();

        std::string getCPF();
        void setCPF(std::string cpf);

        std::string getNome();
        void setNome(std::string nome);

        int getQuantidade();

};

#endif
