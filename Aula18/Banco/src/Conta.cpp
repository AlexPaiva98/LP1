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

std::string Conta::getNumero() {
    return this->numero;
}

void Conta::setNumero(std::string numero) {
    this->numero = numero;
}

Cliente Conta::getTitular() {
    return this->titular;
}

void Conta::setTitular(Cliente &titular) {
    this->titular = titular;
}

Agencia Conta::getAgencia() {
    return this->agencia;
}

void Conta::setAgencia(Agencia &agencia) {
    this->agencia = agencia;
}

double Conta::getSaldo() {
    return this->saldo;
}

void Conta::setSaldo(double saldo) {
    if(saldo) {
        this->saldo = saldo;
    }
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
