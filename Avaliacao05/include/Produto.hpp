#ifndef CLASS_PRODUTO
#define CLASS_PRODUTO

#include <string>

class Produto {
    
    private:

        unsigned int codigo;
        std::string nome;
        std::string unidade_medida;
        double preco;
        unsigned int quantidade;

    public:

        Produto();
        ~Produto();

        unsigned int getCodigo();
        void setCodigo(unsigned int codigo);

        std::string getNome();
        void setNome(std::string nome);

        std::string getUnidadeMedida();
        void setUnidadeMedida(std::string unidade_medida);

        double getPreco();
        void setPreco(double preco);

        unsigned int getQuantidade();
        void setQuantidade(unsigned int quantidade);

        double obter_total();
    
};

#endif
