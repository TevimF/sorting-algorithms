#Compilador e flags
CC = g++
CXXFLAGS = -std=c++11 -g -Wall

#Diretorios
INCLUDE_FOLDER = ./include/
SRC_FOLDER = ./src/
OBJ_FOLDER = ./obj/
BIN_FOLDER = ./bin/

#Variáveis de compilação
MAIN = main 
TARGET = pa1.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp) 
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

#Regra para compilar os arquivos .cpp	e transformar em .o
$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE_FOLDER)

# Regra para criar a pasta bin, se não existir
$(shell mkdir -p $(BIN_FOLDER))

# Diretório de objetos
$(shell mkdir -p $(OBJ_FOLDER))

#Regra padrão para compilar o programa e ir para a pasta obj
all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

#Regra para limpar os arquivos de construção
clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)run.out
