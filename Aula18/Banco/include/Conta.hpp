#ifndef CLASS_CONTA
#define CLASS_CONTA

#include <string>

#include "./Cliente.hpp"
#include "./Agencia.hpp"

class Conta {
    
    private:

        std::string numero;
        Cliente titular;
        Agencia agencia;
        double saldo;

        static int quantidade;

    public:
    
        Conta(Cliente titular, Agencia agencia);
        Conta();
        ~Conta();

        std::string getNumero();
        void setNumero(std::string numero);

        Cliente getTitular();
        void setTitular(Cliente &titular);

        Agencia getAgencia();
        void setAgencia(Agencia &agencia);

        double getSaldo();
        void setSaldo(double saldo);

        void sacar(double valor);
        void depositar(double valor);
        void transferir(double valor, Conta &remetente);

};

#endif
