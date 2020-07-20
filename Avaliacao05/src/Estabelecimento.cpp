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
            <<  this->nome_arquivo_estoque 
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
                    unsigned int codigo;
                    std::istringstream (celula) >> codigo;
                    produto.setCodigo(codigo);
                } else if (coluna_atual == 1) { // NOME DO PRODUTO
                    produto.setNome(celula);
                } else if (coluna_atual == 2) { // UNIDADE DE MEDIDA
                    produto.setUnidadeMedida(celula);
                } else if (coluna_atual == 3) { // PREÇO
                    double preco;
                    celula.erase(0, 4);
                    std::istringstream (celula) >> preco;
                    produto.setPreco(preco);
                } else if (coluna_atual == 4) { // QUANTIDADE
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

void Estabelecimento::carregar_vendas() {

    std::ifstream arquivo_leitura(this->nome_arquivo_caixa);
    if (!arquivo_leitura.is_open()) {
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
                    unsigned int codigo;
                    std::istringstream (celula) >> codigo;
                    produto.setCodigo(codigo);
                } else if (coluna_atual == 1) { // NOME DO PRODUTO
                    produto.setNome(celula);
                } else if (coluna_atual == 2) { // UNIDADE DE MEDIDA
                    produto.setUnidadeMedida(celula);
                } else if (coluna_atual == 3) { // PREÇO
                    double preco;
                    celula.erase(0, 4);
                    std::istringstream (celula) >> preco;
                    produto.setPreco(preco);
                } else if (coluna_atual == 4) { // QUANTIDADE
                    unsigned int quantidade;                 
                    std::istringstream (celula) >> quantidade;
                    produto.setQuantidade(quantidade);
                    this->vendas.push(produto);
                }

                coluna_atual++;

            }
        }

        linha_atual++;

    }

    arquivo_leitura.close();

}

Produto * Estabelecimento::obter_produto(std::string produto) {
    for (int i = 0; i < this->produtos.getSize(); i++) {
        Produto * item = this->produtos.getElement(i);
        if (item->getNome() == produto) {
            return item;
        }
    }
    return nullptr;
}

void Estabelecimento::listar(){

    if (this->produtos.getSize()) {

        std::cout << std::endl << "_______Lista de Produtos_______" << std::endl << std::endl;
        std::cout << "- Nome (Unidade de Medida): Preço" << std::endl << std::endl;

        for (int i = 0; i < this->produtos.getSize(); i++) {
            Produto * item = this->produtos.getElement(i);
            if (item->getQuantidade()) {
                std::cout 
                    << "- "
                    << item->getNome() 
                    << " ("
                    << item->getUnidadeMedida() 
                    << "): "
                    << "R$ " 
                    << padronizar_casas_decimais(item->getPreco()) 
                    << std::endl;
            }
        }
        
    } else {

        std::cout << std::endl << "Estoque vazio" << std::endl;
    
    }

    std::cout << std::endl;
    
}

void Estabelecimento::caixa() {

    double total_ganho = 0;

    if (vendas.getSize()) {

        std::cout << std::endl << "_______Lista de Vendas_______" << std::endl << std::endl;
        std::cout << "- Código, Nome, Unidade de Medida, Preço, Quantidade, Total" << std::endl << std::endl;

        for (int i = 0; i < this->vendas.getSize(); i++) {
            Produto * item = this->vendas.getElement(i);
            total_ganho += item->getPreco() * item->getQuantidade();
            std::cout
                << "- "
                << item->getCodigo() 
                << ", "
                << item->getNome() 
                << ", "
                << item->getUnidadeMedida() 
                << ", "
                << "R$ " 
                << padronizar_casas_decimais(item->getPreco()) 
                << ", "
                << item->getQuantidade() 
                << ", "
                << padronizar_casas_decimais(item->getPreco() * item->getQuantidade()) 
                << std::endl;
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

    bool encontrado = false;
    for (int i = 0; i < this->produtos.getSize(); i++) {
        Produto * item = this->produtos.getElement(i);
        if (codigo == item->getCodigo()) {
            if (item->getQuantidade()){
                item->setQuantidade(item->getQuantidade() - 1);
                produto_disponivel = *item;
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
        for (int i = 0; i < this->vendas.getSize(); i++) {
            Produto * item = this->vendas.getElement(i);
            if (codigo == item->getCodigo()) {
                existe = true;
                item->setQuantidade(item->getQuantidade() + 1);
                break;
            }
        }
        if (!existe) {
            produto_disponivel.setQuantidade(1);
            vendas.push(produto_disponivel);
        }
        atualizar_estoque();
        atualizar_vendas();
        std::cout << std::endl << "Venda efetuada com sucesso" << std::endl << std::endl;
    } else {
        std::cout << std::endl << "Produto não encontrado no estoque" << std::endl << std::endl;
    }

}

void Estabelecimento::reabastecer(std::string nome_produto, unsigned int quantidade) {

    for (int i = 0; i < this->produtos.getSize(); i++) {
        Produto * item = this->produtos.getElement(i);
        if (item->getNome() == nome_produto) {
            item->setQuantidade(item->getQuantidade() + quantidade);
        }
    }

    atualizar_estoque();

}

// Escrever no arquivo
void Estabelecimento::atualizar_estoque() {

    std::ofstream arquivo_escrita{this->nome_arquivo_estoque};
    if(!arquivo_escrita.is_open()){
        std::cerr 
            << "O arquivo" 
            << this->nome_arquivo_estoque
            << "não pode ser criado" 
            << std::endl;
        return;
    }

    arquivo_escrita << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE\n";

    for (int i = 0; i < this->produtos.getSize(); i++) {
        Produto * item = this->produtos.getElement(i);
        arquivo_escrita 
            << item->getCodigo() << "," 
            << item->getNome() << ","
            << item->getUnidadeMedida() << ","
            << "\"R$ " << padronizar_casas_decimais(item->getPreco()) << "\","
            << item->getQuantidade() << "\n";
    }

    arquivo_escrita.close();

}

// Escrever no arquivo
void Estabelecimento::atualizar_vendas() {

    std::ofstream arquivo_escrita{this->nome_arquivo_caixa};
    if(!arquivo_escrita.is_open()){
        std::cerr 
            << "O arquivo" 
            << this->nome_arquivo_caixa
            << "não pode ser criado" 
            << std::endl;
        return;
    }
    
    arquivo_escrita << "COD,NOME,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE_VENDIDA,TOTAL\n";
    
    double total_vendas = 0;

    for (int i = 0; i < this->vendas.getSize(); i++) {
        Produto * item = this->vendas.getElement(i);
        total_vendas += item->getQuantidade() * item->getPreco();
        arquivo_escrita 
            << item->getCodigo() << "," 
            << item->getNome() << ","
            << item->getUnidadeMedida() << ","
            << "\"R$ " << padronizar_casas_decimais(item->getPreco()) << "\","
            << item->getQuantidade() << ","
            << "\"R$ " << padronizar_casas_decimais(item->obter_total()) << "\"\n";
    }

    arquivo_escrita 
        << "Total de Vendas: R$" 
        << padronizar_casas_decimais(total_vendas) 
        << "\n";

    arquivo_escrita.close();

}
