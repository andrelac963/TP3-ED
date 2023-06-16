#---------------------------------------------------------------------
# Arquivo		: Makefile
# Conteúdo	: Compilar o programa
# Autor			: André Luiz Alves Costa (andrelac963@gmail.com)
# Histórico	: 2023-00-00 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#					: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/List.o
HDRS = $(INC)/List.h $(INC)/HuffmanCompress.h $(INC)/HuffmanDecompress.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE) descompactado.txt compactado.txt -c

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/List.o: $(HDRS) $(SRC)/List.c
	$(CC) $(CFLAGS) -o $(OBJ)/List.o $(SRC)/List.c

$(OBJ)/HuffmanCompress.o: $(HDRS) $(SRC)/HuffmanCompress.c
	$(CC) $(CFLAGS) -o $(OBJ)/HuffmanCompress.o $(SRC)/HuffmanCompress.c

$(OBJ)/HuffmanDecompress.o: $(HDRS) $(SRC)/HuffmanDecompress.c
	$(CC) $(CFLAGS) -o $(OBJ)/HuffmanDecompress.o $(SRC)/HuffmanDecompress.c
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
