#include <iostream>

#include "../include/Agencia.hpp"
#include "../include/Cliente.hpp"
#include "../include/ClientePJ.hpp"
#include "../include/Conta.hpp"
#include "../include/Fila.hpp"

int main(int argc, char const *argv[]){
    
    Agencia caixa(2003, "Caixa Econômica Federal");

    ClientePJ americanas("Lojas Americanas", "93.526.064/0001-01");
    ClientePJ bahia("Casas Bahia", "03.881.055/0001-46");
    
    Fila <ClientePJ> filaPJ(10);
    filaPJ.push(americanas);
    filaPJ.push(bahia);
    std::cout << filaPJ.back().getRazaoSocial() << std::endl;


    Cliente cliente_pedro("Pedro da Silva", "123.456.789-12");
    Cliente cliente_thiago("Thiago Ferreira", "987.654.321-98");

    Fila <Cliente> filaPF(10);
    filaPF.push(cliente_pedro);
    filaPF.push(cliente_thiago);
    std::cout << filaPF.back().getNome() << std::endl;
    
    Conta conta_pedro(cliente_pedro, caixa);
    Conta conta_thiago(cliente_thiago, caixa);

    conta_pedro.depositar(1000);
    conta_pedro.sacar(300);
    conta_pedro.transferir(500, conta_thiago);

    return 0;

}
