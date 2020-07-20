#include "../include/ClientePF.hpp"

int ClientePF::quantidade;

ClientePF::ClientePF(std::string nome, std::string cpf, Endereco &endereco): Cliente(endereco){
    this->nome = nome;
    this->cpf = cpf;
    this->quantidade += 1;
}

ClientePF::ClientePF(){
    this->quantidade += 1;
}

ClientePF::~ClientePF(){
    
}

std::string ClientePF::getCPF() {
    return this->cpf;
}

void ClientePF::setCPF(std::string cpf) {
    this->cpf = cpf;
}

std::string ClientePF::getNome() {
    return this->nome;
}

void ClientePF::setNome(std::string nome) {
    this->nome = nome;
}

int ClientePF::getQuantidade() {
    return this->quantidade;
}