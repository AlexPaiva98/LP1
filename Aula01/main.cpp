#include <iostream>

// using namespace std

int main(int argc, char* argv[]){ // Mesma estrutura do C
    
    int n1 = 0;
    int n2 = 0;

    std::cout << "Informe o primeiro número: "; //  c + out (imprimir)
    std::cin >> n1;

    std::cout << "Informe o segundo número: "; // c + in (informar)
    std::cin >> n2;

    int sum = n1 + n2;

    std::cout << "A soma dos números é "<< sum << std::endl; 
    // Flush: funciona como um await (espera o comando terminar, limpa o baffer). 
    // É garantido que a linha em branco vai ser impressa na tela

    return 0;
}

// Gerar arquivo compilado: g++ -std=c++11 -o [NOME_PROGRAMA] [ARQUIVO_COM_INSTRUÇÕES]

// By Alex Sandro de Paiva