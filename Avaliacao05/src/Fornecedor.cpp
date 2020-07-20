#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/Fornecedor.hpp"
#include "../include/Produto.hpp"

Fornecedor::Fornecedor(std::string nome_arquivo_fornecedor) {
    this->nome_arquivo_fornecedor = nome_arquivo_fornecedor;
    carregar_produtos();
}

Fornecedor::~Fornecedor() {
}

void Fornecedor::carregar_produtos() {

    std::ifstream arquivo_leitura(this->nome_arquivo_fornecedor);
    if (!arquivo_leitura.is_open()) {
        std::cerr 
            << "Arquivo " 
            <<  this->nome_arquivo_fornecedor 
            << " não existente ou sem permissão de leitura" 
            << std::endl;
        return;
    }
    
    std::string linha;

    int linha_atual = 0;

    while (!arquivo_leitura.eof()) {

        std::getline(arquivo_leitura, linha);

        if (linha.size() == 0) {
            continue;
        }

        if (linha_atual) { // Ignorar a primeira linha (cabeçalho)
        
            std::stringstream linha_auxiliar(linha); // String mais manipulável, para filtrar os dados

            Produto produto;

            int coluna_atual = 0;

            while(linha_auxiliar.good()) {

                std::string celula;
                
                std::getline(linha_auxiliar, celula, ',');

                if (coluna_atual == 0){ // NOME DO PRODUTO
                    produto.setNome(celula);
                } else if (coluna_atual == 1) { // QUANTIDADE
                    unsigned int quantidade;
                    std::istringstream (celula) >> quantidade;
                    produto.setQuantidade(quantidade);
                    this->produtos.push(produto);
                }

                coluna_atual++;

            }
        }

        linha_atual++;

    }

    arquivo_leitura.close();

}

void Fornecedor::listarProdutos() {

    // Melhorar a exibição
    std::cout << std::endl;

    if (produtos.getSize()) {
        
        std::cout << "Lista de Produtos Disponíveis para Abastecimento" << std::endl << std::endl;
        std::cout << "Nome do Produto: Quantidade" << std::endl;

        for (int i = 0; i < produtos.getSize(); i++) {

            Produto * element = produtos.getElement(i);

            if (element->getQuantidade()) {
                std::cout 
                    << element->getNome() 
                    << ": " 
                    << element->getQuantidade()
                    << std::endl;
            }

        }

    } else {
        std::cout << std::endl << "Abastecimento vazio" << std::endl;
    }

    // Melhorar a exibição
    std::cout << std::endl;

}

bool Fornecedor::repassarProdutos(std::string nome_produto, unsigned int quantidade) {
    
    for (int i = 0; i < produtos.getSize(); i++) {

        Produto * element = produtos.getElement(i);

        if (element->getNome() == nome_produto) {
            if (element->getQuantidade() >= quantidade) {
                Produto new_element = *element;
                new_element.setQuantidade(new_element.getQuantidade() - quantidade);
                produtos.update(i, new_element);
                atualizar_abastecimento();
                return true;
            } else {
                std::cout << "Quantidade indisponível" << std::endl;
                return false;
            }
        }
    
    }
    
    std::cout << "Produto não encontrado" << std::endl;
    return false;
    
}

void Fornecedor::atualizar_abastecimento() {

    std::ofstream arquivo_escrita{this->nome_arquivo_fornecedor};
    if(!arquivo_escrita.is_open()){
        std::cerr 
            << "O arquivo " 
            << this->nome_arquivo_fornecedor
            << " não pode ser criado" 
            << std::endl;
        return;
    }
    
    arquivo_escrita << "PRODUTO,QUANTIDADE\n";
    
    for (int i = 0; i < produtos.getSize(); i++) {

        Produto * element = produtos.getElement(i);
        
        arquivo_escrita
            << element->getNome() 
            << ","
            << element->getQuantidade()
            << "\n";

    }

    arquivo_escrita.close();

}
