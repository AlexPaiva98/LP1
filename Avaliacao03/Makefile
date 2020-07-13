GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall -O2
PROGRAMA = diary

all: $(PROGRAMA)

$(PROGRAMA): main.o Config.o App.o Diary.o Message.o Date.o Time.o Aux.o
	@echo "Compilando meu programa(diário)..."
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Config.o App.o Diary.o Message.o Date.o Time.o Aux.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Config.o: src/Config.cpp include/Config.h
	$(GCC) $(GCC_FLAGS) -c src/Config.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Message.o: src/Message.cpp include/Message.h
	$(GCC) $(GCC_FLAGS) -c src/Message.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

Aux.o: src/Aux.cpp include/Aux.h
	$(GCC) $(GCC_FLAGS) -c src/Aux.cpp

.PHONY: all

clean:
	rm -rf *.o
	rm -rf diary diary.md
