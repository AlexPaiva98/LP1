#include <iostream>

#include "../include/Carro.hpp"

int main (int argc, char const *argv[]) {
    
    Carro fiat("FIAT UNO", "Branco", 4);
    Carro ford("Ford Fiesta Sedan", "Vermelho", 2);

    std::cout << "Tipo do Carro: " << fiat.tipo << std::endl;
    std::cout << "Cor: " << fiat.cor << std::endl;
    std::cout << "Quantidade de Portas: " << fiat.numero_portas << std::endl;

    std::cout << "Tipo do Carro: " << ford.tipo << std::endl;
    std::cout << "Cor: " << ford.cor << std::endl;
    std::cout << "Quantidade de Portas: " << ford.numero_portas << std::endl;

    std::cout << "Quantidade de Carros: " << fiat.quantidade << std::endl;

    return 0;

}