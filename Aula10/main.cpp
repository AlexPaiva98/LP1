#include <iostream>

void por_copia(int a){
    a = 20;
}

void por_referencia(int &a) {
    a = 30;
}

void por_ponteiro(int *a) {
    *a = 40;
}

int main(int argc, char *argv[]){
    
    int a = 10;
    int* b = &a; // o ponteiro b está apontando/recebendo o endereço de a
    
    // *b = acessar o valor
    // *b = 20 => print() => 20
    std::cout << *b << std::endl;

    int n = 10;
    int &n2 = n; // Referencia, não pode ser null, apelido de n
    std::cout << n << std::endl;

    int arr[] = {10, 20, 30, 40};

    // *(arr + 1), evitar arr = arr + 1 (++)

    return 0;
}
