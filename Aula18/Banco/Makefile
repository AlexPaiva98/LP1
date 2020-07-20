GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -O2
PROGRAMA = banco

all: $(PROGRAMA)

$(PROGRAMA): main.o Conta.o Cliente.o ClientePF.o ClientePJ.o Agencia.o include/Fila.hpp Endereco.o Funcionario.o Gerente.o Seguranca.o Caixa.o
	@echo "Compilando meu programa..."
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Conta.o Cliente.o ClientePF.o ClientePJ.o Agencia.o Endereco.o Funcionario.o Gerente.o Seguranca.o Caixa.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp include/Conta.hpp
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp include/Cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

ClientePF.o: src/ClientePF.cpp include/ClientePF.hpp
	$(GCC) $(GCC_FLAGS) -c src/ClientePF.cpp

ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.hpp
	$(GCC) $(GCC_FLAGS) -c src/ClientePJ.cpp

Agencia.o: src/Agencia.cpp include/Agencia.hpp
	$(GCC) $(GCC_FLAGS) -c src/Agencia.cpp

Endereco.o: src/Endereco.cpp include/Endereco.hpp
	$(GCC) $(GCC_FLAGS) -c src/Endereco.cpp

Funcionario.o: src/Funcionario.cpp include/Funcionario.hpp
	$(GCC) $(GCC_FLAGS) -c src/Funcionario.cpp

Gerente.o: src/Gerente.cpp include/Gerente.hpp
	$(GCC) $(GCC_FLAGS) -c src/Gerente.cpp

Seguranca.o: src/Seguranca.cpp include/Seguranca.hpp
	$(GCC) $(GCC_FLAGS) -c src/Seguranca.cpp

Caixa.o: src/Caixa.cpp include/Caixa.hpp
	$(GCC) $(GCC_FLAGS) -c src/Caixa.cpp

clean:
	rm -rf *.o
	rm -rf $(PROGRAMA)
