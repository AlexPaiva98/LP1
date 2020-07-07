#include "../include/Conta.hpp"

void Conta::sacar(double valor){
    if(valor > this->saldo){
        return;
    }
    this->saldo -= valor;
};

void Conta::depositar(double valor){
    this->saldo += valor;
};

void Conta::transferir(double valor, Conta &remetente) {
    if(valor > this->saldo){
        return;
    }
    saldo -= valor;
    remetente.depositar(valor);
};
