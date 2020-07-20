#ifndef CLASS_GERENTE
#define CLASS_GERENTE

#include <string>

#include "Funcionario.hpp"

class Gerente: public Funcionario {
    
    private:

        std::string perfil;
        double salario;

    public:
    
        Gerente(Endereco &endereco, std::string inicio_expediente, std::string fim_expediente, std::string nome, std::string perfil, double salario);
        Gerente();
        ~Gerente();
        
        std::string getPerfil();
        void setPerfil(std::string perfil);
        
        double getSalario();
        void setSalario(double salario);

        void emitirRelatorio(int mes, int ano);

};

#endif
