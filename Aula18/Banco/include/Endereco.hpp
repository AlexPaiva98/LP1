#ifndef CLASS_ENDERECO
#define CLASS_ENDERECO

#include <string>

class Endereco  {
    
    private:

        std::string estado;
        std::string cidade;
        std::string bairro;
        std::string logradouro;

    public:
    
        Endereco(std::string estado, std::string cidade, std::string bairro, std::string logradouro);
        Endereco();
        ~Endereco();

        std::string getEstado();
        void setEstado(std::string estado);

        std::string getCidade();
        void setCidade(std::string cidade);

        std::string getBairro();
        void setBairro(std::string bairro);

        std::string getLogradouro();
        void setLogradouro(std::string logradouro);

};

#endif
