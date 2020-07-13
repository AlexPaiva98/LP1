#include <iostream>

#include "../include/Empresa.hpp"

int main(int argc, char const *argv[]) {

    Empresa empresa("31.557.929/0001-40", "Crefisa");

    std::cout << "Desejas adicionar quantos funcionários? ";
    int quantidade;
    std::cin >> quantidade;
    std::cin.ignore();
    
    empresa.adicionarFuncionarios(quantidade);

    empresa.aumentarSalario("TI");

    empresa.listarFuncionarios();

    return 0;

}
