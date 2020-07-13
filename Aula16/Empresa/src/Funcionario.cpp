#include <iostream>

#include "../include/Funcionario.hpp"

Funcionario::Funcionario(){
}

Funcionario::~Funcionario(){
}

std::string Funcionario::getNome() {
    return this->nome;
}

void Funcionario::setNome(std::string nome) {
    this->nome = nome;
}

double Funcionario::getSalario() {
    return this->salario;
}

void Funcionario::setSalario(double salario) {
    if (salario >= 0) {
        this->salario = salario;
    } else {
        std::cout << "Salário inválido" << std::endl;
    }
}

std::string Funcionario::getEmpresa() {
    return this->empresa;
}

void Funcionario::setEmpresa(std::string empresa) {
    this->empresa = empresa;
}

std::string Funcionario::getDataAdmissao() {
    return this->data_admissao;
}

void Funcionario::setDataAdmissao(std::string data_admissao) {
    this->data_admissao = data_admissao;
}

std::string Funcionario::getDepartamento() {
    return this->departamento;
}

void Funcionario::setDepartamento(std::string departamento) {
    this->departamento = departamento;
}
