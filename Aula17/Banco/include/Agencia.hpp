#ifndef CLASS_AGENCIA
#define CLASS_AGENCIA

#include <string>

class Agencia {
    
    private:
        unsigned int numero;
        std::string nome;

    public:
        Agencia(unsigned int numero, std::string nome);
        Agencia();
        ~Agencia();

        unsigned int getNumero();
        void setNumero(unsigned int numero);

        std::string getNome();
        void setNome(std::string nome);

};

#endif
