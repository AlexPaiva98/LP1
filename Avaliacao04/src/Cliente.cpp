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

void Cliente::comprar(Produto &produto){

    bool existe = false;

    for (auto &item: sacola) {
        if (produto.codigo == item.codigo) {
            existe = true;
        }
    }

    if (!existe) {
        if (saldo >= produto.preco){
            saldo -= produto.preco;
            sacola.push_back(produto);
            std::cout << std::endl << "Sucesso! Produto adicionado" << std::endl << std::endl;
        } else {
            std::cout << std::endl << "Saldo insuficiente" << std::endl << std::endl;
        }
    } else {
        std::cout << std::endl << "Produto já inserido" << std::endl << std::endl;
    }

}

void Cliente::ver_sacola() {

    if (sacola.size()) {
        std::cout << std::endl << "_______Sacola de Compras_______" << std::endl << std::endl;
        std::cout << "Código | Produto | Unidade de Medida | Preço" << std::endl;

        for (auto &item: sacola) {

            std::cout << item.codigo << " | ";
            std::cout << item.nome << " | ";
            std::cout << item.unidade_medida << " | ";
            std::cout << "R$ " << padronizar_casas_decimais(item.preco) << std::endl;
        }
    } else {
        std::cout << std::endl << "Sacola vazia" << std::endl;
    }

    std::cout << std::endl;

}

void Cliente::registrar() {

    if (sacola.size()) {
    
        std::stringstream nome_arquivo;
        nome_arquivo << "cliente" << this->quantidade << ".txt";

        std::ofstream arquivo_escrita{nome_arquivo.str()};
        if(!arquivo_escrita.is_open()){
            std::cerr << "O arquivo não pode ser criado" << std::endl << std::endl;
            return;
        }
        
        arquivo_escrita << "COD, NOME, UNIDADE DE MEDIDA, PREÇO\n";
        
        for (auto &item: sacola) {
            arquivo_escrita 
                << item.codigo << "," 
                << item.nome << ","
                << item.unidade_medida << ","
                << "\"R$ " << padronizar_casas_decimais(item.preco) << "\"\n";
        }

        arquivo_escrita.close();

        sacola.clear();
    
    } else {

        std::cout << "Sacola vazia" << std::endl << std::endl;

    }

}
