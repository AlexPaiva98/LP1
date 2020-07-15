#include "../include/ClientePJ.hpp"

int ClientePJ::quantidade;

ClientePJ::ClientePJ(std::string razao_social, std::string cnpj){
    this->razao_social = razao_social;
    this->cnpj = cnpj;
    this->quantidade += 1;
}

ClientePJ::ClientePJ(){
    this->quantidade += 1;
}

ClientePJ::~ClientePJ(){
    
}

std::string ClientePJ::getRazaoSocial() {
    return this->razao_social;
}

void ClientePJ::setRazaoSocial(std::string razao_social) {
    this->razao_social = razao_social;
}

std::string ClientePJ::getCNPJ() {
    return this->cnpj;
}

void ClientePJ::setCNPJ(std::string cnpj) {
    this->cnpj = cnpj;
}

int ClientePJ::getQuantidade() {
    return this->quantidade;
}
