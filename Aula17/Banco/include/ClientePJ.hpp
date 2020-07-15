#ifndef CLASS_CLIENTEPJ
#define CLASS_CLIENTEPJ

#include <string>

class ClientePJ {
    
    private:
        std::string razao_social;
        std::string cnpj;
        static int quantidade;

    public:
        ClientePJ(std::string razao_social, std::string cnpj);
        ClientePJ();
        ~ClientePJ();

        std::string getRazaoSocial();
        void setRazaoSocial(std::string razao_social);

        std::string getCNPJ();
        void setCNPJ(std::string cnpj);

        int getQuantidade();

};

#endif
