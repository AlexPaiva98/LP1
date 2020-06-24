#include "../include/Diary.h"

int main(int argc, char* argv[]){

    Diary diary("diary.md");

    diary.add("Teste 1");
    diary.add("Teste 2");
    diary.add("Teste 3");

    diary.list();

    return 0;

}
