#include "../include/Funcionario.hpp"

Funcionario::Funcionario(
    Endereco &endereco, 
    std::string inicio_expediente, 
    std::string fim_expediente, 
    std::string nome) {
        this->endereco = endereco;
        this->inicio_expediente = inicio_expediente;
        this->fim_expediente = fim_expediente;
        this->nome = nome;
}

Funcionario::Funcionario() {

}

Funcionario::~Funcionario() {

}

Endereco Funcionario::getEndereco() {
    return this->endereco;
}

void Funcionario::setEndereco(Endereco &endereco) {
    this->endereco = endereco;
}

std::string Funcionario::getInicioExpediente() {
    return this->inicio_expediente;
}

void Funcionario::setInicioExpediente(std::string inicio_expediente) {
    this->inicio_expediente = inicio_expediente;
}

std::string Funcionario::getFimExpediente() {
    return this->fim_expediente;
}

void Funcionario::setFimExpediente(std::string fim_expediente) {
    this->fim_expediente = fim_expediente;
}

std::string Funcionario::getNome() {
    return this->nome;
}

void Funcionario::setNome(std::string nome) {
    this->nome = nome;
}
