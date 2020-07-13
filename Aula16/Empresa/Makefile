GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -O2
PROGRAMA = empresa

all: $(PROGRAMA)

$(PROGRAMA): main.o Empresa.o Funcionario.o
	@echo "Compilando meu programa..."
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Empresa.o Funcionario.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Empresa.o: src/Empresa.cpp include/Empresa.hpp
	$(GCC) $(GCC_FLAGS) -c src/Empresa.cpp

Funcionario.o: src/Funcionario.cpp include/Funcionario.hpp
	$(GCC) $(GCC_FLAGS) -c src/Funcionario.cpp

clean:
	rm -rf *.o
	rm -rf $(PROGRAMA)
