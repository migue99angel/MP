BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
ZIP=./zip
DOC=./doc
OPT=-Wall -g
PRJ=practica2

bin/intervalo.bin: $(OBJ)/main.o $(OBJ)/intervalo.o
	g++ $(OBJ)/intervalo.o $(OBJ)/main.o -o $(BIN)/intervalo.bin
obj/intervalo.o: $(INC)/intervalo.h $(SRC)/intervalo.cpp
	g++ $(OPT) -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INC)
obj/main.o: $(SRC)/main.cpp $(INC)/intervalo.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)
	

zip: clean
	@echo "Generando ZIP del proyecto $(PRJ): "
	zip -r $(ZIP)/$(PRJ).zip *

clean:
	rm -f $(BIN)/* $(OBJ)/*

doxy: 
	doxygen $(DOC)/intervalo.doxy 
