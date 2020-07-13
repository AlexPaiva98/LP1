#include <iostream>

#include "../include/Estabelecimento.hpp"
#include "../include/Cliente.hpp"

void acoes_cliente() {

    std::cout << "1. Lista de produtos disponíveis" << std::endl;
    std::cout << "2. Adicionar produto na sacola de compras" << std::endl;
    std::cout << "3. Ver sacola de compras" << std::endl;
    std::cout << "4. Finalizar compra" << std::endl;

}

void menu_cliente(Estabelecimento &estabelecimento) {
    
    double saldo;
    std::cout << std::endl << "Saldo (R$): ";
    std::cin >> saldo;

    std::cout << std::endl;

    Cliente cliente(saldo);

    int y = 1;
    while (y) {

        acoes_cliente();

        std::cout << std::endl << "Escolha: ";
        std::cin >> y;
        
        std::cout << std::endl;

        if (y == 4) {
            
            for (auto &item: cliente.sacola) {
                estabelecimento.vender(item.codigo);
            }
            cliente.registrar();

            break;

        } else if (y == 3) {

            cliente.ver_sacola();

        }  else if (y == 2) {

            std::cin.ignore();
            
            unsigned codigo = 0;
            std::cout << "Código do Produto: ";
            std::cin >> codigo;

            Produto * ponteiro_produto = estabelecimento.obter_produto(codigo);
            if (ponteiro_produto != nullptr) {
                cliente.comprar(*ponteiro_produto);
            } else {
                std::cout << std::endl << "Produto inválido" << std::endl << std::endl;
            }

        }  else if (y == 1) {
            estabelecimento.listar();
        } else {
            std::cout << std::endl << "Opção inválida" << std::endl << std::endl;
        }
    
    }

}

void acoes_gerais() {

    std::cout << "1. Fazer compras" << std::endl;
    std::cout << "2. Ver caixa" << std::endl;
    std::cout << "3. Sair" << std::endl;

}

void menu_aplicacao(Estabelecimento &estabelecimento) {
    
    std::cout << std::endl << "_______Sistema de Compras_______" << std::endl << std::endl;
    
    int x = 1;
    while (x) {
        
        acoes_gerais();
        
        std::cout << std::endl << "Escolha: ";
        std::cin >> x;

        if (x == 3) {
            break;
        } else if (x == 2) {
            estabelecimento.caixa();
        } else if (x == 1) {
            menu_cliente(estabelecimento);
        } else {
            std::cout << std::endl << "Opção inválida" << std::endl << std::endl;
        }
    
    }

    std::cout << std::endl;

}

int main(int argc, char const *argv[]) {
    
    Estabelecimento supermercado_sao_francisco("estoque.csv", "caixa.csv");

    menu_aplicacao(supermercado_sao_francisco);
        
    return 0;

}
