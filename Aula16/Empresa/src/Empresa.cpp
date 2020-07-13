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

void Empresa::adicionarFuncionario(Funcionario funcionario) {
   
    this->funcionarios.push_back(funcionario);

}

void Empresa::aumentarSalario(std::string departamento) {
    for (auto &funcionario: funcionarios) {
        if (funcionario.getDepartamento() == departamento) {
            funcionario.setSalario(funcionario.getSalario() * 1.1);
        }
    }
}

void Empresa::listarFuncionarios() {
    for (auto &funcionario: funcionarios) {

        std::cout << std::endl << "_______________Lista de Funcionários_______________" << std::endl << std::endl;

        std::cout << "Nome: " << funcionario.getNome() << std::endl;
        std::cout << "Salário: " << funcionario.getSalario() << std::endl;
        std::cout << "Data de Admissão: " << funcionario.getDataAdmissao() << std::endl;
        std::cout << "Departamento: " << funcionario.getDepartamento() << std::endl;

    }
}
