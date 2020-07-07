#include <iostream>

#include "../include/Conta.hpp"

int main(int argc, char const *argv[]){
    
    Conta pedro;
    
    pedro.numero = "0003256";
    pedro.titular.cpf = "123.456.789-12";
    pedro.titular.nome = "Pedro da Silva";
    pedro.agencia.nome = "Caixa Econômica";
    pedro.agencia.numero = 2003;
    pedro.saldo = 0;

    pedro.depositar(1000);
    pedro.sacar(300);

    std::cout << "Titular: " << pedro.titular.nome << std::endl;
    std::cout << "Saldo: "  << pedro.saldo << std::endl << std::endl;

    Conta thiago;

    thiago.numero = "0004821";
    thiago.titular.nome = "Thiago Ferreira";
    thiago.titular.cpf = "987.654.321-98";
    pedro.agencia.nome = "Caixa Econômica";
    pedro.agencia.numero = 2006;
    thiago.saldo = 0;

    pedro.transferir(500, thiago);

    std::cout << "Titular: " << pedro.titular.nome << std::endl;
    std::cout << "Saldo: "  << pedro.saldo << std::endl << std::endl;
    
    std::cout << "Titular: " << thiago.titular.nome << std::endl;
    std::cout << "Saldo: "  << thiago.saldo << std::endl << std::endl;

    return 0;
}
