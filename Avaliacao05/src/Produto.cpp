#include "../include/Produto.hpp"

Produto::Produto() {
    this->quantidade = 1;
}

Produto::~Produto(){
}

unsigned int Produto::getCodigo() {
    return this->codigo;
}

void Produto::setCodigo(unsigned int codigo) {
    this->codigo = codigo;
}

std::string Produto::getNome() {
    return this->nome;
}

void Produto::setNome(std::string nome) {
    this->nome = nome;
}

std::string Produto::getUnidadeMedida() {
    return this->unidade_medida;
}

void Produto::setUnidadeMedida(std::string unidade_medida) {
    this->unidade_medida = unidade_medida;
}

double Produto::getPreco() {
    return this->preco;
}

void Produto::setPreco(double preco) {
    this->preco = preco;
}

unsigned int Produto::getQuantidade() {
    return this->quantidade;
}

void Produto::setQuantidade(unsigned int quantidade) {
    this->quantidade = quantidade;
}

double Produto::obter_total() {
    return this->quantidade * this->preco;
}
