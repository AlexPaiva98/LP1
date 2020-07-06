#include <iostream>

#include "../include/Conta.hpp"

int main(int argc, char const *argv[]){
    
    Conta pedro;
    
    pedro.numero = "0003256";
    pedro.titular = "Pedro da Silva";
    pedro.saldo = 0;

    pedro.depositar(1000);
    pedro.sacar(300);

    std::cout << "Titular: " << pedro.titular << std::endl;
    std::cout << "Saldo: "  << pedro.saldo << std::endl << std::endl;

    Conta thiago;

    thiago.numero = "0004821";
    thiago.titular = "Thiago Ferreira";
    thiago.saldo = 0;

    pedro.transferir(500, thiago);

    std::cout << "Titular: " << pedro.titular << std::endl;
    std::cout << "Saldo: "  << pedro.saldo << std::endl << std::endl;
    
    std::cout << "Titular: " << thiago.titular << std::endl;
    std::cout << "Saldo: "  << thiago.saldo << std::endl << std::endl;

    return 0;
}
