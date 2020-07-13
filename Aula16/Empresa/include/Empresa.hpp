#ifndef CLASS_EMPRESA
#define CLASS_EMPRESA

#include <string>
#include <vector>

#include "../include/Funcionario.hpp"

class Empresa {
    
    private:

        std::string cnpj;
        std::string nome;
        
        std::vector<Funcionario> funcionarios;

    public:

        Empresa(std::string cnpj, std::string nome);
        ~Empresa();

        std::string getCNPJ();
        void setCNPJ(std::string cnpj);

        std::string getNome();
        void setNome(std::string nome);

        void adicionarFuncionario(Funcionario funcionario);
        void aumentarSalario(std::string departamento);

        void listarFuncionarios();

};

#endif
