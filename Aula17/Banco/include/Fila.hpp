#include <iostream>

template <class CLIENTE>
class Fila{
    private:
        int size;
        int top;
        CLIENTE* elements;

    public:
        Fila(int size){
            this->size = size;
            this->top = -1;
            this->elements = new CLIENTE[this->size];
        }

        void push(CLIENTE element){
            if(this->top == (this->size - 1)){
                std::cout << "Fila cheia" << std::endl;
            }else{
                this->elements[++top] = element;
            }
        }

        void pop(){
            if(this->top == -1){
                std::cout << "Fila vazia" << std::endl;
            }else{
                CLIENTE* update_elements = new CLIENTE[this->size];
                for (int i = 0; i < this->size; i++) {
                    if (i == 0) {
                        continue;
                    }
                    update_elements[i - 1] = this->elements[i];
                }
                delete[] this->elements;
                this->elements = update_elements;
            }
        }

        CLIENTE front(){
            return this->elements[0];
        }

        CLIENTE back(){
            return this->elements[this->top];
        }

        bool isEmpty(){
            if(this->top == -1){
                return true;
            }else{
                return false;
            }
        }

};
