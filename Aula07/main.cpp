#include <iostream>

int main(int argc, char *argv[]) {

    int *a = new int[3000];
    float *f = new float;

    // new = malloc
    // delete = free

    delete a;
    delete f;

    return 0;

}
