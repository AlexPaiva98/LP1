#ifndef CLASS_CONTA
#define CLASS_CONTA

#include <string>

class Conta {
    
    public:
        std::string numero;
        std::string titular;
        double saldo;
    
    void sacar(double valor);
    void depositar(double valor);
    void transferir(double valor, Conta &remetente);

};

#endif
