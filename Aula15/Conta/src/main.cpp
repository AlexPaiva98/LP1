#include <iostream>

#include "../include/Agencia.hpp"
#include "../include/Cliente.hpp"
#include "../include/Conta.hpp"

int main(int argc, char const *argv[]){
    
    Agencia caixa(2003, "Caixa Econômica Federal");

    Cliente cliente_pedro("Pedro da Silva", "123.456.789-12");
    Conta conta_pedro(cliente_pedro, caixa);

    conta_pedro.depositar(1000);
    conta_pedro.sacar(300);

    std::cout << "Titular Pedro: " << conta_pedro.titular.nome << std::endl;
    std::cout << "Saldo: "  << conta_pedro.saldo << std::endl << std::endl;

    Cliente cliente_thiago("Thiago Ferreira", "987.654.321-98");
    Conta conta_thiago(cliente_thiago, caixa);

    conta_pedro.transferir(500, conta_thiago);

    std::cout << "Titular: " << conta_pedro.titular.nome << std::endl;
    std::cout << "Saldo: "  << conta_pedro.saldo << std::endl << std::endl;
    
    std::cout << "Titular: " << conta_thiago.titular.nome << std::endl;
    std::cout << "Saldo: "  << conta_thiago.saldo << std::endl << std::endl;

    std::cout << "Quantidade de Clientes: " << cliente_pedro.quantidade << std::endl;
    std::cout << "Quantidade de Contas: " << conta_pedro.quantidade << std::endl;

    return 0;
}
