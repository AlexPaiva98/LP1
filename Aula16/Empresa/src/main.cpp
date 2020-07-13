#include <iostream>

#include "../include/Empresa.hpp"

int main(int argc, char const *argv[]) {

    Empresa empresa("31.557.929/0001-40", "Crefisa");

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

        empresa.adicionarFuncionario(funcionario);

    }
    
    empresa.aumentarSalario("TI");

    empresa.listarFuncionarios();

    return 0;

}
