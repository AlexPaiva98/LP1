#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/Cliente.hpp"
#include "../include/Aux.hpp"

int Cliente::quantidade;

Cliente::Cliente(double saldo) {
    this->saldo = saldo;
    this->quantidade ++;
}

Cliente::~Cliente(){

}

double Cliente::getSaldo() {
    return this->saldo;
}

void Cliente::setSaldo(double saldo) {
    this->saldo = saldo;
}

Vector<Produto> * Cliente::getSacola() {
    return &this->sacola;
}

void Cliente::comprar(Produto &produto){

    bool existe = false;

    for (int i = 0; i < this->sacola.getSize(); i++){
        if(this->sacola.getElement(i)->getCodigo() == produto.getCodigo()) {
            existe = true;
        }
    }

    if (!existe) {
        if (this->saldo >= produto.getPreco()){
            this->saldo -= produto.getPreco();
            sacola.push(produto);
            std::cout << std::endl << "Sucesso! Produto adicionado" << std::endl << std::endl;
        } else {
            std::cout << std::endl << "Saldo insuficiente" << std::endl << std::endl;
        }
    } else {
        std::cout << std::endl << "Produto já inserido" << std::endl << std::endl;
    }

}

void Cliente::ver_sacola() {

    if (sacola.getSize()) {
        std::cout << std::endl << "_______Sacola de Compras_______" << std::endl << std::endl;
        std::cout << "- Produto (Unidade de Medida): Preço" << std::endl << std::endl;

        for (int i = 0; i < this->sacola.getSize(); i++){
            Produto * item = this->sacola.getElement(i);
            std::cout 
                << "- "
                << item->getNome()
                << " ("
                << item->getUnidadeMedida() 
                << "): "
                << "R$ "
                << padronizar_casas_decimais(item->getPreco()) 
                << std::endl;
        }

    } else {
        std::cout << std::endl << "Sacola vazia" << std::endl;
    }

    std::cout << std::endl;

}

void Cliente::registrar() {

    if (sacola.getSize()) {
    
        std::stringstream nome_arquivo;
        nome_arquivo << "cliente" << this->quantidade << ".txt";

        std::ofstream arquivo_escrita{nome_arquivo.str()};
        if(!arquivo_escrita.is_open()){
            std::cerr << "O arquivo não pode ser criado" << std::endl << std::endl;
            return;
        }
        
        arquivo_escrita << "COD, NOME, UNIDADE DE MEDIDA, PREÇO\n";
        
        for (int i = 0; i < this->sacola.getSize(); i++){
            Produto * item = this->sacola.getElement(i);
            arquivo_escrita 
                << item->getCodigo() << "," 
                << item->getNome() << ","
                << item->getUnidadeMedida() << ","
                << "\"R$ " << padronizar_casas_decimais(item->getPreco()) << "\"\n";
        }

        arquivo_escrita.close();

        sacola.clear();
    
    } else {

        std::cout << "Sacola vazia" << std::endl << std::endl;

    }

}
