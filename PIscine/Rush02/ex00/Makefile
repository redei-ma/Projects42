# Variabili
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = functions.h
TARGET = rush-02
SRC = main.c funct1.c funct2.c funct3.c
OBJ = main.o funct1.o funct2.o funct3.o

# Regola principale
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regole per i file oggetto
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

# Regola per pulire i file compilati
clean:
	rm -f $(OBJ) $(TARGET)

# Regola per le dipendenze
.PHONY: all clean
