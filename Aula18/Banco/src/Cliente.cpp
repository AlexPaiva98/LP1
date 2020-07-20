#include "../include/Cliente.hpp"

Cliente::Cliente(Endereco &endereco) {
    this->endereco = endereco;
}

Cliente::Cliente() {

}

Cliente::~Cliente() {

}

Endereco Cliente::getEndereco() {
    return this->endereco;
}

void Cliente::setEndereco(Endereco &endereco) {
    this->endereco = endereco;
}
