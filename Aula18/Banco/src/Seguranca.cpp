#include "../include/Seguranca.hpp"

Seguranca::Seguranca(
    Endereco &endereco, 
    std::string inicio_expediente, 
    std::string fim_expediente, 
    std::string nome, 
    double salario): Funcionario(endereco, inicio_expediente, fim_expediente, nome) {
        this->salario = salario;
}

Seguranca::Seguranca() {

}

Seguranca::~Seguranca() {

}

double Seguranca::getSalario() {
    return this->salario;
}

void Seguranca::setSalario(double salario) {
    this->salario = salario;
}

bool Seguranca::vistoriarFuncionario(Funcionario &funcionario) {
    std::string horario_atual = "10:35:16"; // A ideia é obter isso de maneira automática, pelo relógio do sistema
    // Se o horário atual estiver entre o início e fim do expediente do funcionário, o mesmo está habilitado
    return true;
}
