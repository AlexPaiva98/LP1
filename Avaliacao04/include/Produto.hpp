#ifndef CLASS_PRODUTO
#define CLASS_PRODUTO

#include <string>

class Produto {
    
    public:
        unsigned int codigo;
        std::string nome;
        std::string unidade_medida;
        double preco;
        unsigned int quantidade;
    
    Produto();
    ~Produto();

    double obter_total();
    
};

#endif
