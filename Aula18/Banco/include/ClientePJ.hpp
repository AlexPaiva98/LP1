#ifndef CLASS_CLIENTE_PJ
#define CLASS_CLIENTE_PJ

#include <string>

#include "Cliente.hpp"

class ClientePJ: public Cliente {
    
    private:

        std::string razao_social;
        std::string cnpj;
        static int quantidade;

    public:
    
        ClientePJ(std::string razao_social, std::string cnpj, Endereco &endereco);
        ClientePJ();
        ~ClientePJ();

        std::string getRazaoSocial();
        void setRazaoSocial(std::string razao_social);

        std::string getCNPJ();
        void setCNPJ(std::string cnpj);

        int getQuantidade();

};

#endif
