GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -O2
PROGRAMA = carro

all: $(PROGRAMA)

$(PROGRAMA): main.o Carro.o Motor.o
	@echo "Compilando meu programa..."
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Carro.o Motor.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Carro.o: src/Carro.cpp include/Carro.hpp
	$(GCC) $(GCC_FLAGS) -c src/Carro.cpp

Motor.o: src/Motor.cpp include/Motor.hpp
	$(GCC) $(GCC_FLAGS) -c src/Motor.cpp

clean:
	rm -rf *.o
	rm -rf $(PROGRAMA)
