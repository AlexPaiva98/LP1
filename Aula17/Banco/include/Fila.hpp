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
            this->elements = new CLIENTE[size];
        }

        void push(CLIENTE element){
            if(this->top == (this->size - 1)){
                std::cout << "Fila cheia" << std::endl;
            }else{
                this->elements[++this->top] = element;
            }
        }

        void pop(){
            if(this->top == -1){
                std::cout << "Fila vazia" << std::endl;
            }else{
                this->elements[this->top++];
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
