GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -O2
PROGRAMA = Supermercado

all: $(PROGRAMA)

$(PROGRAMA): main.o Cliente.o Estabelecimento.o Produto.o Aux.o Fornecedor.o
	@echo "Compilando meu programa..."
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Cliente.o Estabelecimento.o Produto.o Aux.o Fornecedor.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Cliente.o: src/Cliente.cpp include/Cliente.hpp include/Vector_Supermercado.hpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.hpp include/Vector_Supermercado.hpp
	$(GCC) $(GCC_FLAGS) -c src/Fornecedor.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.hpp include/Vector_Supermercado.hpp
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Produto.o: src/Produto.cpp include/Produto.hpp
	$(GCC) $(GCC_FLAGS) -c src/Produto.cpp

Aux.o: src/Aux.cpp include/Aux.hpp
	$(GCC) $(GCC_FLAGS) -c src/Aux.cpp

clean:
	rm -rf *.o
	rm -rf *.txt
	rm -rf caixa.csv
	rm -rf $(PROGRAMA)
