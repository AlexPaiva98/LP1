#include <iostream>

#include "../include/Estabelecimento.hpp"
#include "../include/Cliente.hpp"
#include "../include/Fornecedor.hpp"

void finalizar_compra(Estabelecimento &estabelecimento, Cliente &cliente) {
    Vector<Produto> * sacola = cliente.getSacola();
    for (int i = 0; i < sacola->getSize(); i++) {
        estabelecimento.vender(sacola->getElement(i)->getCodigo());
    }
    cliente.registrar();
}

void adicionar_produto(Estabelecimento &estabelecimento, Cliente &cliente) {
    
    std::cin.ignore();
            
    std::string nome_produto;
    std::cout << "Produto(nome): ";
    std::cin >> nome_produto;

    Produto * ponteiro_produto = estabelecimento.obter_produto(nome_produto);
    if (ponteiro_produto != nullptr) {
        cliente.comprar(*ponteiro_produto);
    } else {
        std::cout << std::endl << "Produto não encontrado" << std::endl << std::endl;
    }

}

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
            finalizar_compra(estabelecimento, cliente);
            break;
        } else if (y == 3) {
            cliente.ver_sacola();
        }  else if (y == 2) {
            adicionar_produto(estabelecimento, cliente);
        }  else if (y == 1) {
            estabelecimento.listar();
        } else {
            std::cout << std::endl << "Opção inválida" << std::endl << std::endl;
        }
    
    }

}

void repor_produtos(Estabelecimento &estabelecimento, Fornecedor &fornecedor) {
    
    std::string nome_produto;
    std::cout << "Produto(nome): ";
    std::cin >> nome_produto;

    unsigned int quantidade_reposicao;
    std::cout << "Quantidade: ";
    std::cin >> quantidade_reposicao;

    std::cout << std::endl;

    if (fornecedor.repassarProdutos(nome_produto, quantidade_reposicao)) {
        estabelecimento.reabastecer(nome_produto, quantidade_reposicao);
        std::cout 
            << "Sucesso! O produto " 
            << nome_produto 
            << " foi reposto em "  
            << quantidade_reposicao
            << (quantidade_reposicao > 1 ? " unidades" : " unidade")
            << std::endl;
    }

    std::cout << std::endl;
}

void acoes_gerais() {

    std::cout << "1. Fazer compras" << std::endl;
    std::cout << "2. Ver caixa" << std::endl;
    std::cout << "3. Listar os produtos do fornecedor" << std::endl;
    std::cout << "4. Reabastecer estoque do estabelecimento" << std::endl;
    std::cout << "5. Sair" << std::endl;

}

void menu_aplicacao(Estabelecimento &estabelecimento, Fornecedor &fornecedor) {
    
    std::cout << std::endl << "_______Sistema de Compras_______" << std::endl << std::endl;
    
    int x = 1;
    while (x) {
        
        acoes_gerais();
        
        std::cout << std::endl << "Escolha: ";
        std::cin >> x;

        if (x == 5) {
            break;
        } else if (x == 4) {
            repor_produtos(estabelecimento, fornecedor);
        } else if (x == 3) {
            fornecedor.listarProdutos();
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
    
    Fornecedor fornecedor("fornecedor.csv");

    Estabelecimento supermercado_sao_francisco("estoque.csv", "caixa.csv");

    menu_aplicacao(supermercado_sao_francisco, fornecedor);

    return 0;

}
