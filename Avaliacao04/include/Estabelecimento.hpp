#ifndef CLASS_ESTABELECIMENTO
#define CLASS_ESTABELECIMENTO

#include <list>
#include <string>

#include "./Produto.hpp"

class Estabelecimento {
    
    public:
        std::string nome_arquivo_estoque;
        std::string nome_arquivo_caixa;
        std::list<Produto> produtos;
        std::list<Produto> vendas;
    
    Estabelecimento(std::string nome_arquivo_estoque, std::string nome_arquivo_caixa);
    ~Estabelecimento();
    
    void carregar_produtos();
    void carregar_vendas();

    void listar();
    void caixa();
    void vender(unsigned int codigo);

    Produto * obter_produto(unsigned int codigo);
    void atualizar_estoque();
    void atualizar_vendas();
    
};

#endif
