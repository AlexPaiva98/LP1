#ifndef CLASS_CONTA
#define CLASS_CONTA

#include <string>

#include "./Cliente.hpp"
#include "./Agencia.hpp"

class Conta {
    
    public:
        std::string numero;
        Cliente titular;
        Agencia agencia;
        double saldo;
    
    void sacar(double valor);
    void depositar(double valor);
    void transferir(double valor, Conta &remetente);

};

#endif
