#ifndef CLASS_CLIENTE
#define CLASS_CLIENTE

#include "Endereco.hpp"

class Cliente  {
    
    private:

        Endereco endereco;

    public:
        
        Cliente(Endereco &endereco);
        Cliente();
        ~Cliente();

        Endereco getEndereco();
        void setEndereco(Endereco &endereco);

};

#endif
