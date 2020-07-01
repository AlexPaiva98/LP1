#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

/*
struct Qualquer {

};
*/

int main(int argc, char* argv[]){

    {
        std::vector<int> items; // Se auto-ajusta mediante ao eventos de add e rm
        // std::vector<Qualquer> items2;
        // std::vector<float> items3;
        // std::vector<bool> items4;

        items.push_back(10); // Armazena na memória HEAP, parâmetro por cópia
        items.push_back(5); 
        
        for (std::vector<int>::iterator i = items.begin(); i != items.end(); i++) {
            std::cout << *i << std::endl;
        }

        std::sort(items.begin(), items.end());

        // range for loop
        for(int i: itens){
            std::cout << i << std::endl;
        }
    }

    {
        std::unordered_map<std::string, int> dicionario;

        dicionario["Alex"] = 10;
        dicionario["Maria"] = 9;

        for (std::unordered_map<std::string, int>::iterator i = dicionario.begin(); i != dicionario.end(); i++) {
            std::cout << i->first << std::endl; // Chave
            std::cout << i->second << std::endl; // Valor
        }

        // O compilador infere o tipo
        for (auto i = dicionario.begin(); i != dicionario.end(); i++) {
            std::cout << i->first << std::endl; // Chave
            std::cout << i->second << std::endl; // Valor
        }

    }

    return 0;

}
