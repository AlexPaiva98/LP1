#include <iostream>

#include "../include/Caixa.hpp"

Caixa::Caixa(
    Endereco &endereco, 
    std::string inicio_expediente, 
    std::string fim_expediente, 
    std::string nome, 
    double salario): Funcionario(endereco, inicio_expediente, fim_expediente, nome) {
    this->salario = salario;
}

Caixa::Caixa(){

}

Caixa::~Caixa() {

}

double Caixa::getSalario() {
    return this->salario;
}

void Caixa::setSalario(double salario) {
    this->salario = salario;
}

void Caixa::verClientePessoaFisica(ClientePF &clientePF){
    std::cout << "CPF: " << clientePF.getCPF() << std::endl;
    std::cout << "Nome: " << clientePF.getNome() << std::endl;
    std::cout << "Estado de Residência: " << clientePF.getEndereco().getEstado() << std::endl;
}

void Caixa::verClientePessoaJuridica(ClientePJ &clientePJ){
    std::cout << "CPF: " << clientePJ.getCNPJ() << std::endl;
    std::cout << "Razão Social: " << clientePJ.getRazaoSocial() << std::endl;
    std::cout << "Estado de Residência: " << clientePJ.getEndereco().getEstado() << std::endl;
}
