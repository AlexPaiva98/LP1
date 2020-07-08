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
