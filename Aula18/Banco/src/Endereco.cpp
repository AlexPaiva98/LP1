#include "../include/Endereco.hpp"

Endereco::Endereco(std::string estado, std::string cidade, std::string bairro, std::string logradouro) {
    this->estado = estado;
    this->cidade = cidade;
    this->bairro = bairro;
    this->logradouro = logradouro;
}

Endereco::Endereco() {

}

Endereco::~Endereco() {

}

std::string Endereco::getEstado() {
    return this->estado;
}

void Endereco::setEstado(std::string estado) {
    this->estado = estado;
}

std::string Endereco::getCidade() {
    return this->cidade;
}

void Endereco::setCidade(std::string cidade) {
    this->cidade = cidade;
}

std::string Endereco::getBairro() {
    return this->bairro;
}

void Endereco::setBairro(std::string bairro) {
    this->bairro = bairro;
}

std::string Endereco::getLogradouro() {
    return this->logradouro;
}

void Endereco::setLogradouro(std::string logradouro) {
    this->logradouro = logradouro;
}
