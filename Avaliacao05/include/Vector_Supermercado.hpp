#ifndef TEMPLATE_VECTOR
#define TEMPLATE_VECTOR

template <class V>
class Vector{
    private:

        int capacity;
        int size;
        V* elements;

        void increaseStructure() {
            this->capacity *= 2;
            V* new_elements = new V[this->capacity];
            for (int i = 0; i < this->size; i++) {
                new_elements[i] = this->elements[i];
            }
            delete[] this->elements;
            this->elements = new_elements;
        }

    public:

        Vector(){
            this->capacity = 1;
            this->size = 0;
            this->elements = new V[this->capacity];
        }

        ~Vector() {
            delete[] this->elements;
        }

        void push(V element){
            if (this->size == this->capacity){
                increaseStructure();
            }
            this->elements[this->size] = element;
            this->size++;
        }

        void update(int position, V element) {
            if (position >= 0 && position <= this->size) {
                this->elements[position] = element;
            }
        }

        void pop(int position){
            if (position >= 0 && position <= this->size) {
                V* new_elements = new V[this->capacity];
                int k = 0;
                for (int i = 0; i < this->size; i++) {
                    if (i == position) {
                        continue;
                    }
                    new_elements[k] = this->elements[i];
                    k++;
                }
                this->size = k;
                delete[] this->elements;
                this->elements = new_elements;
            }
        }

        void clear() {
            delete[] this->elements;
            this->capacity = 1;
            this->size = 0;
            V* new_elements = new V[this->capacity];
            this->elements = new_elements;
        }

        int getCapacity() {
            return this->capacity;
        }

        int getSize() {
            return this->size;
        }

        V * getElement(int position) {
            if(position >= 0 && position <= this->size) {
                return &this->elements[position];
            }
            return nullptr;
        }

        V front(){
            return this->elements[0];
        }

        V back(){
            return this->elements[this->size];
        }

        bool isEmpty() {
            if(this->size == 0){
                return true;
            }else{
                return false;
            }
        }

};

#endif