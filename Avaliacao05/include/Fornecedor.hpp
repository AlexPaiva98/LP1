#ifndef CLASS_FORNECEDOR
#define CLASS_FORNECEDOR

#include "./Produto.hpp"
#include "./Vector_Supermercado.hpp"

class Fornecedor {
    
    private:
        std::string nome_arquivo_fornecedor;
        Vector<Produto> produtos;

        // Métodos auxiliares
        void carregar_produtos();
        void atualizar_abastecimento();

    public:
        
        Fornecedor(std::string nome_arquivo_fornecedor);
        ~Fornecedor();

        // Métodos requisitados na avaliação
        void listarProdutos();
        bool repassarProdutos(std::string nome_produto, unsigned int quantidade);

};

#endif
