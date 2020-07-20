#ifndef CLASS_FUNCIONARIO
#define CLASS_FUNCIONARIO

#include <string>

#include "Endereco.hpp"

class Funcionario  {
    
    private:

        Endereco endereco;
        std::string inicio_expediente;
        std::string fim_expediente;
        std::string nome;

    public:
        
        Funcionario(Endereco &endereco, std::string inicio_expediente, std::string fim_expediente, std::string nome);
        Funcionario();
        ~Funcionario();

        Endereco getEndereco();
        void setEndereco(Endereco &endereco);

        std::string getInicioExpediente();
        void setInicioExpediente(std::string inicio_expediente);

        std::string getFimExpediente();
        void setFimExpediente(std::string fim_expediente);
        
        std::string getNome();
        void setNome(std::string nome);
    
};

#endif
