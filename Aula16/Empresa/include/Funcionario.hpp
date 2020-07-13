#ifndef CLASS_FUNCIONARIO
#define CLASS_FUNCIONARIO

#include <string>

class Funcionario {
    
    private:

        std::string nome;
        double salario;
        std::string data_admissao;
        std::string departamento;

    public:

        Funcionario();
        ~Funcionario();

        std::string getNome();
        void setNome(std::string nome);

        double getSalario();
        void setSalario(double salario);

        std::string getDataAdmissao();
        void setDataAdmissao(std::string data_admissao);

        std::string getDepartamento();
        void setDepartamento(std::string departamento);

};

#endif
