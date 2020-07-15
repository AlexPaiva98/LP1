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
    ClientePJ shoptime("Shoptime", "71.685.790/0001-34");
    ClientePJ submarino("Submarino", "96.740.009/0001-08");

    Fila <ClientePJ> filaPJ(10);
    filaPJ.push(americanas);
    filaPJ.push(bahia);
    filaPJ.push(shoptime);
    filaPJ.push(submarino);
    std::cout << std::endl << "_____Fila de Pessoas Jurídica_____" << std::endl;
    std::cout << "Primeira: " << filaPJ.front().getRazaoSocial() << std::endl;
    std::cout << "Última: " << filaPJ.back().getRazaoSocial() << std::endl << std::endl;

    Cliente cliente_pedro("Pedro da Silva", "123.456.789-12");
    Cliente cliente_thiago("Thiago Ferreira", "987.654.321-98");

    Fila <Cliente> filaPF(10);
    filaPF.push(cliente_pedro);
    filaPF.push(cliente_thiago);
    std::cout << "_____Fila de Pessoas Físicas_____" << std::endl;
    std::cout << "Primeira: " << filaPF.front().getNome() << std::endl;
    std::cout << "Última: " << filaPF.back().getNome() << std::endl << std::endl;

    Conta conta_pedro(cliente_pedro, caixa);
    Conta conta_thiago(cliente_thiago, caixa);

    conta_pedro.depositar(1000);
    conta_pedro.sacar(300);
    conta_pedro.transferir(500, conta_thiago);

    return 0;

}
