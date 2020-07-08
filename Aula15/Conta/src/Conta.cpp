#include "../include/Conta.hpp"

int Conta::quantidade;

Conta::Conta(Cliente titular, Agencia agencia){
    this->titular = titular;
    this->agencia = agencia;
    this->quantidade += 1;
}

Conta::Conta(){
    this->quantidade += 1;
}

Conta::~Conta(){
    
}

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
