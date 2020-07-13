#include <iostream>

#include "../include/Empresa.hpp"

Empresa::Empresa(std::string cnpj, std::string nome) {
    this->cnpj = cnpj;
    this->nome = nome;
}

Empresa::~Empresa() {
}

std::string Empresa::getCNPJ() {
    return this->cnpj;
}

void Empresa::setCNPJ(std::string cnpj) {
    this->cnpj = cnpj;
}

std::string Empresa::getNome() {
    return this->nome;
}

void Empresa::setNome(std::string nome) {
    this->nome = nome;
}
