#ifndef CLASS_ESTABELECIMENTO
#define CLASS_ESTABELECIMENTO

#include <string>

#include "./Produto.hpp"
#include "./Fornecedor.hpp"

class Estabelecimento {
    
    private:

        std::string nome_arquivo_estoque;
        std::string nome_arquivo_caixa;
        Vector<Produto> produtos;
        Vector<Produto> vendas;

        void carregar_produtos();
        void carregar_vendas();

        void atualizar_estoque();
        void atualizar_vendas();

    public:
    
        Estabelecimento(std::string nome_arquivo_estoque, std::string nome_arquivo_caixa);
        ~Estabelecimento();
        
        void listar();
        void caixa();
        void vender(unsigned int codigo);
        void reabastecer(std::string nome_produto, unsigned int quantidade);

        Produto * obter_produto(std::string produto);

};

#endif
