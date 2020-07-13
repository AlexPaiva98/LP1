#include <iostream>
#include <list>

#include "../include/Empresa.hpp"


void listarFuncionarios(std::list<Funcionario> &funcionarios) {
    for (auto &funcionario: funcionarios) {

        std::cout << std::endl;

        std::cout << "Nome: " << funcionario.getNome() << std::endl;
        std::cout << "Salário: " << funcionario.getSalario() << std::endl;
        std::cout << "Empresa: " << funcionario.getEmpresa() << std::endl;
        std::cout << "Data de Admissão: " << funcionario.getDataAdmissao() << std::endl;
        std::cout << "Departamento: " << funcionario.getDepartamento() << std::endl;
    
    }
}

void aumentarSalario(std::list<Funcionario> &funcionarios) {
    
    std::cout << "Desejas aumentar em 10% os salários dos funcionários condizentes a qual departamento? ";
    std::string departamento;
    std::cin >> departamento;
    std::cin.ignore();

    for (auto &funcionario: funcionarios) {
        if (funcionario.getDepartamento() == departamento) {
            funcionario.setSalario(funcionario.getSalario() * 1.1);
        }
    }
}

void inserirFuncionarios(std::list<Funcionario> &funcionarios) {

    std::cout << "Desejas adicionar quantos funcionários? ";
    size_t quantidade;
    std::cin >> quantidade;
    std::cin.ignore();

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

        funcionarios.push_back(funcionario);

    }
}

int main(int argc, char const *argv[]) {

    Empresa empresa("31.557.929/0001-40", "Crefisa");
    
    std::list<Funcionario> funcionarios;

    inserirFuncionarios(funcionarios);

    aumentarSalario(funcionarios);
    
    listarFuncionarios(funcionarios);
    
    return 0;

}
