#include "../include/Cliente.hpp"

int Cliente::quantidade;

Cliente::Cliente(std::string nome, std::string cpf){
    this->nome = nome;
    this->cpf = cpf;
    this->quantidade += 1;
}

Cliente::Cliente(){
    this->quantidade += 1;
}

Cliente::~Cliente(){
    
}

std::string Cliente::getCPF() {
    return this->cpf;
}

void Cliente::setCPF(std::string cpf) {
    this->cpf = cpf;
}

std::string Cliente::getNome() {
    return this->nome;
}

void Cliente::setNome(std::string nome) {
    this->nome = nome;
}

int Cliente::getQuantidade() {
    return this->quantidade;
}