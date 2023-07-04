#---------------------------------------------------------------------
# Arquivo		: Makefile
# Conteúdo	: Compilar o programa
# Autor			: André Luiz Alves Costa (andrelac963@gmail.com)
# Histórico	: 2023-00-00 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#					: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/HuffmanCompress.o $(OBJ)/HuffmanDecompress.o $(OBJ)/Node.o $(OBJ)/List.o $(OBJ)/Tree.o $(OBJ)/Dictionary.o 
HDRS = $(INC)/Exceptions.hpp $(INC)/HuffmanCompress.hpp $(INC)/HuffmanDecompress.hpp $(INC)/Node.hpp $(INC)/List.hpp $(INC)/Tree.hpp $(INC)/Dictionary.hpp
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE) texto.txt compactado.bin -c
	$(EXE) compactado.bin descompactado.txt -d

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/HuffmanCompress.o: $(HDRS) $(SRC)/HuffmanCompress.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/HuffmanCompress.o $(SRC)/HuffmanCompress.cpp

$(OBJ)/HuffmanDecompress.o: $(HDRS) $(SRC)/HuffmanDecompress.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/HuffmanDecompress.o $(SRC)/HuffmanDecompress.cpp

$(OBJ)/Node.o: $(HDRS) $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Node.o $(SRC)/Node.cpp

$(OBJ)/List.o: $(HDRS) $(SRC)/List.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/List.o $(SRC)/List.cpp

$(OBJ)/Tree.o: $(HDRS) $(SRC)/Tree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Tree.o $(SRC)/Tree.cpp

$(OBJ)/Dictionary.o: $(HDRS) $(SRC)/Dictionary.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Dictionary.o $(SRC)/Dictionary.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out compactado.bin descompactado.txt $(BIN)/*