#ifndef CLASS_CAIXA
#define CLASS_CAIXA

#include "Funcionario.hpp"
#include "ClientePF.hpp"
#include "ClientePJ.hpp"

class Caixa: public Funcionario {
    
    private:

        double salario;

    public:
        
        Caixa(Endereco &endereco, std::string inicio_expediente, std::string fim_expediente, std::string nome, double salario);
        Caixa();
        ~Caixa();

        double getSalario();
        void setSalario(double salario);

        void verClientePessoaFisica(ClientePF &clientePF);
        void verClientePessoaJuridica(ClientePJ &clientePJ);

};

#endif
