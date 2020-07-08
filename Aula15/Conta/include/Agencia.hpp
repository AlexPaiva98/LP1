#ifndef CLASS_AGENCIA
#define CLASS_AGENCIA

#include <string>

class Agencia {
    
    public:
        unsigned int numero;
        std::string nome;

    Agencia(unsigned int numero, std::string nome);
    Agencia();
    ~Agencia();

};

#endif
