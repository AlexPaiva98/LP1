#include "../include/Produto.hpp"

Produto::Produto() {
    this->quantidade = 1;
}

Produto::~Produto(){
}

double Produto::obter_total() {
    return this->quantidade * this->preco;
}