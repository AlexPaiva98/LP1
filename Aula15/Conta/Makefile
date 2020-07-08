GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -O2
PROGRAMA = conta

all: $(PROGRAMA)

$(PROGRAMA): main.o Conta.o Cliente.o Agencia.o
	@echo "Compilando meu programa..."
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Conta.o Cliente.o Agencia.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.hpp
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp include/Cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Agencia.o: src/Agencia.cpp include/Agencia.hpp
	$(GCC) $(GCC_FLAGS) -c src/Agencia.cpp

clean:
	rm -rf *.o
	rm -rf $(PROGRAMA)
