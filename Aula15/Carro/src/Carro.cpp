#include "../include/Carro.hpp"

int Carro::quantidade;

Carro::Carro(std::string tipo, std::string cor, int numero_portas){
    this->tipo = tipo;
    this->cor = cor;
    this->numero_portas = numero_portas;
    this->quantidade += 1;
}

Carro::Carro(){
    this->quantidade += 1;
}

Carro::~Carro() {

}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligar(){
    motor.partida();
}
