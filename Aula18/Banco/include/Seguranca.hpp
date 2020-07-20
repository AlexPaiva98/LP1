#ifndef CLASS_SEGURANCA
#define CLASS_SEGURANCA

#include <string>

#include "Funcionario.hpp"

class Seguranca: public Funcionario {
    
    private:

        double salario;

    public:

        Seguranca(Endereco &endereco, std::string inicio_expediente, std::string fim_expediente, std::string nome, double salario);
        Seguranca();
        ~Seguranca();

        double getSalario();
        void setSalario(double salario);

        bool vistoriarFuncionario(Funcionario &funcionario);

};

#endif
