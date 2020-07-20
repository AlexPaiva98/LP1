#ifndef CLASS_CLIENTE
#define CLASS_CLIENTE

#include "./Produto.hpp"
#include "./Vector_Supermercado.hpp"

class Cliente {
    
    private:

        double saldo;
        Vector<Produto> sacola;
        static int quantidade;
    
    public:

        Cliente(double saldo);
        ~Cliente();

        Vector<Produto> * getSacola();

        double getSaldo();
        void setSaldo(double saldo);
        
        void comprar(Produto &produto);
        void ver_sacola();
        void registrar();

};

#endif
