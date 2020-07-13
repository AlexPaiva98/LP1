#ifndef CLASS_CLIENTE
#define CLASS_CLIENTE

#include <vector>

#include "./Produto.hpp"

class Cliente {
    
    public:
        double saldo;
        std::vector<Produto> sacola; 
    
    static int quantidade;
    
    Cliente(double saldo);
    ~Cliente();
    
    void comprar(Produto &produto);
    void ver_sacola();
    void registrar();

};

#endif
