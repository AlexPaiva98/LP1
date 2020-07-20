#include "../include/Agencia.hpp"

Agencia::Agencia(unsigned int numero, std::string nome){
    this->numero = numero;
    this->nome = nome;
}

Agencia::Agencia(){
}

Agencia::~Agencia(){
    
}

unsigned int Agencia::getNumero() {
    return this->numero;
}

void Agencia::setNumero(unsigned int numero) {
    this->numero = numero;
}

std::string Agencia::getNome() {
    return this->nome;
}

void Agencia::setNome(std::string nome) {
    this->nome = nome;
}
