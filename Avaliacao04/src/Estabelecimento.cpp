#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/Estabelecimento.hpp"
#include "../include/Aux.hpp"

Estabelecimento::Estabelecimento(std::string nome_arquivo_estoque, std::string nome_arquivo_caixa){
    
    this->nome_arquivo_estoque = nome_arquivo_estoque;
    this->nome_arquivo_caixa = nome_arquivo_caixa;

    carregar_produtos();
    carregar_vendas();

}

Estabelecimento::~Estabelecimento(){
}

void Estabelecimento::carregar_produtos() {
    
    std::ifstream arquivo_leitura(this->nome_arquivo_estoque);
    if (!arquivo_leitura.is_open()) {
        std::cerr 
            << "Arquivo " 
            <<  nome_arquivo_estoque 
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

                if (coluna_atual == 0){ // CODIGO
                    std::istringstream (celula) >> produto.codigo;
                } else if (coluna_atual == 1) { // NOME DO PRODUTO
                    produto.nome = celula;
                } else if (coluna_atual == 2) { // UNIDADE DE MEDIDA
                    produto.unidade_medida = celula;
                } else if (coluna_atual == 3) { // PREÇO
                    celula.erase(0, 4);
                    std::istringstream (celula) >> produto.preco;
                } else if (coluna_atual == 4) { // QUANTIDADE
                    std::istringstream (celula) >> produto.quantidade;                
                    this->produtos.push_back(produto);
                }

                coluna_atual++;

            }
        }

        linha_atual++;

    }

    arquivo_leitura.close();

}

void Estabelecimento::carregar_vendas() {

    std::ifstream arquivo_leitura(this->nome_arquivo_caixa);
    if (!arquivo_leitura.is_open()) {
        // std::cerr 
        //     << "Arquivo" 
        //     <<  nome_arquivo_caixa 
        //     << "não existente ou sem permissão de leitura" 
        //     << std::endl;
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
                
                if (coluna_atual == 0){ // CODIGO
                    std::istringstream (celula) >> produto.codigo;
                } else if (coluna_atual == 1) { // NOME DO PRODUTO
                    produto.nome = celula;
                } else if (coluna_atual == 2) { // UNIDADE DE MEDIDA
                    produto.unidade_medida = celula;
                } else if (coluna_atual == 3) { // PREÇO
                    celula.erase(0, 4);
                    std::istringstream (celula) >> produto.preco;
                } else if (coluna_atual == 4) { // QUANTIDADE                    
                    std::istringstream (celula) >> produto.quantidade;
                    this->vendas.push_back(produto);
                }

                coluna_atual++;

            }
        }

        linha_atual++;

    }

    arquivo_leitura.close();

}

Produto * Estabelecimento::obter_produto(unsigned int codigo) {
    for (auto &produto: produtos) {
        if (produto.codigo == codigo) {
            return &produto;
        }
    }
    return nullptr;
}

void Estabelecimento::listar(){

    if (produtos.size()) {

        std::cout << std::endl << "Lista de Produtos" << std::endl << std::endl;
        std::cout << "Código | Nome | Unidade de Medida | Preço" << std::endl;

        for (auto &produto: produtos) {
            if(produto.quantidade) {
                std::cout << produto.codigo << " | ";
                std::cout << produto.nome << " | ";
                std::cout << produto.unidade_medida << " | ";
                std::cout << "R$ " << padronizar_casas_decimais(produto.preco) << std::endl;
            }
        }
        
    } else {

        std::cout << std::endl << "Estoque vazio" << std::endl;
    
    }

    std::cout << std::endl;
    
}

void Estabelecimento::caixa() {

    double total_ganho = 0;

    if (vendas.size()) {

        std::cout << std::endl << "Lista de Vendas" << std::endl << std::endl;
        std::cout << "Código | Nome | Unidade de Medida | Preço | Quantidade | Total" << std::endl;

        for (auto &venda: vendas) {
            total_ganho += venda.preco * venda.quantidade;
            std::cout << venda.codigo << " | ";
            std::cout << venda.nome << " | ";
            std::cout << venda.unidade_medida << " | ";
            std::cout << "R$ " << padronizar_casas_decimais(venda.preco) << " | ";
            std::cout << venda.quantidade << " | ";
            std::cout << padronizar_casas_decimais(venda.preco * venda.quantidade) << std::endl;
        }

        std::cout 
            << std::endl 
            << "Receita Total: R$ " 
            << padronizar_casas_decimais(total_ganho) 
            << std::endl 
            << std::endl;

    } else {

        std::cout << std::endl << "Nenhuma venda efetuada" << std::endl << std::endl;

    }

}

void Estabelecimento::vender(unsigned int codigo) {

    Produto produto_disponivel;

    // Verificar possibilidade de compra
    bool encontrado = false;
    for (auto &produto: produtos) {
        if (codigo == produto.codigo) {
            if (produto.quantidade){
                produto.quantidade --;
                produto_disponivel = produto;
                encontrado = true;
                break;
            } else {
                std::cout << std::endl << "Produto indisponível no momento" << std::endl << std::endl;
                return;
            }
        }
    }

    if (encontrado) {
        // Verificar se já existe alguma venda
        bool existe = false;
        for (auto &venda: vendas) {
            if (codigo == venda.codigo) {
                existe = true;
                venda.quantidade += 1;                
                break;
            }
        }
        if (!existe) {
            produto_disponivel.quantidade = 1;
            vendas.push_back(produto_disponivel);
        }
        atualizar_estoque();
        atualizar_vendas();
        std::cout << std::endl << "Venda efetuada com sucesso" << std::endl << std::endl;
    } else {
        std::cout << std::endl << "Produto não encontrado no estoque" << std::endl << std::endl;
    }

}

// Escrever no arquivo
void Estabelecimento::atualizar_estoque() {

    std::ofstream arquivo_escrita{this->nome_arquivo_estoque};
    if(!arquivo_escrita.is_open()){
        std::cerr 
            << "O arquivo" 
            << nome_arquivo_estoque
            << "não pode ser criado" 
            << std::endl;
        return;
    }

    arquivo_escrita << "COD, PRODUTO, UNIDADE DE MEDIDA, PREÇO, QUANTIDADE\n";

    for (auto &produto: produtos) {
        arquivo_escrita 
            << produto.codigo << "," 
            << produto.nome << ","
            << produto.unidade_medida << ","
            << "\"R$ " << padronizar_casas_decimais(produto.preco) << "\","
            << produto.quantidade << "\n";
    }

    arquivo_escrita.close();

}

// Escrever no arquivo
void Estabelecimento::atualizar_vendas() {

    std::ofstream arquivo_escrita{this->nome_arquivo_caixa};
    if(!arquivo_escrita.is_open()){
        std::cerr 
            << "O arquivo" 
            << nome_arquivo_caixa
            << "não pode ser criado" 
            << std::endl;
        return;
    }
    
    arquivo_escrita << "COD, NOME, UNIDADE DE MEDIDA, PREÇO, QUANTIDADE_VENDIDA, TOTAL\n";
    
    double total_vendas = 0;

    for (auto &venda: vendas) {

        total_vendas += venda.quantidade * venda.preco;

        arquivo_escrita 
            << venda.codigo << "," 
            << venda.nome << ","
            << venda.unidade_medida << ","
            << "\"R$ " << padronizar_casas_decimais(venda.preco) << "\","
            << venda.quantidade << ","
            << "\"R$ " << padronizar_casas_decimais(venda.obter_total()) << "\"\n";
    }

    arquivo_escrita 
        << "Total de Vendas: R$" 
        << padronizar_casas_decimais(total_vendas) 
        << "\n";

    arquivo_escrita.close();

}
