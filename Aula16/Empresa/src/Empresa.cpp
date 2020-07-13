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

void Empresa::adicionarFuncionarios(unsigned int quantidade) {
    for (size_t i = 0; i < quantidade; i++){
        
        Funcionario funcionario;

        std::cout 
            << std::endl 
            << "_______________Funcionário " 
            << i + 1 
            << "_______________" 
            << std::endl;
                
        std::string nome;
        std::cout << "Nome: ";
        std::cin >> nome;
        std::cin.ignore();
        funcionario.setNome(nome);


        double salario;
        std::cout << "Salário: ";
        std::cin >> salario;
        std::cin.ignore();
        funcionario.setSalario(salario);

        std::string data_admissao;
        std::cout << "Data de Admissão: ";
        std::cin >> data_admissao;
        std::cin.ignore();
        funcionario.setDataAdmissao(data_admissao);

        std::string departamento;
        std::cout << "Departamento: ";
        std::cin >> departamento;
        std::cin.ignore();
        funcionario.setDepartamento(departamento);

        this->funcionarios.push_back(funcionario);

    }

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
