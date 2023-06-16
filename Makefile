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
OBJS = $(OBJ)/main.o $(OBJ)/huffmanCompress.o $(OBJ)/huffmanDecompress.o
HDRS = $(INC)/huffmanCompress.hpp $(INC)/huffmanDecompress.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE) descompactado.txt compactado.txt -c
	$(EXE) compactado.txt descompactado-final.txt -d

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/huffmanCompress.o: $(HDRS) $(SRC)/huffmanCompress.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/huffmanCompress.o $(SRC)/huffmanCompress.cpp

$(OBJ)/huffmanDecompress.o: $(HDRS) $(SRC)/huffmanDecompress.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/huffmanDecompress.o $(SRC)/huffmanDecompress.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
