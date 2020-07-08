#ifndef CLASS_CARRO
#define CLASS_CARRO

#include <string>

#include "./Motor.hpp"

class Carro {
    
    public:
        std::string tipo;
        std::string cor;
        std::string placa;
        int numero_portas;
        int velocidade;
        Motor motor;
    
    static int quantidade;

    Carro(std::string tipo, std::string cor, int numero_portas);
    Carro();
    ~Carro();

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligar();

};

#endif
