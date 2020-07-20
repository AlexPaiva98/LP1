#include <iostream>

#include "../include/Gerente.hpp"

Gerente::Gerente(
        Endereco &endereco, 
        std::string inicio_expediente, 
        std::string fim_expediente, 
        std::string nome, 
        std::string perfil, 
        double salario
    ): Funcionario(endereco, inicio_expediente, fim_expediente, nome) {
    this->salario = salario;
    this->perfil = perfil;
}

Gerente::Gerente() {

}

Gerente::~Gerente() {

}

std::string Gerente::getPerfil() {
    return this->perfil;
}

void Gerente::setPerfil(std::string perfil) {
    this->perfil = perfil;
}

double Gerente::getSalario() {
    return this->salario;
}

void Gerente::setSalario(double salario) {
    this->salario = salario;
}

void Gerente::emitirRelatorio(int mes, int ano) {
    std::cout << "Relatório " << mes << "/" << ano << std::endl;
    std::cout << "Foram adicionados N clientes" << std::endl;
}
