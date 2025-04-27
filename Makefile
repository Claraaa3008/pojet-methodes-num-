# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
OBJ = main.o euler.o RK4.o fonction.o
EXEC = simulation
TXT = Mtn.txt Mtn_rk4.txt Mtn_euler.txt

# Règle principale
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) -lm

# Compilation des fichiers .c en .o
main.o: main.c euler.h RK4.h fonction.h
	$(CC) $(CFLAGS) -c main.c

euler.o: euler.c euler.h fonction.h
	$(CC) $(CFLAGS) -c euler.c

fonction.o: fonction.c fonction.h
	$(CC) $(CFLAGS) -c fonction.c

RK4.o: RK4.c RK4.h
	$(CC) $(CFLAGS) -c RK4.c
# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ) $(EXEC) $(TXT)

# Nettoyage complet
fclean: clean

# Recompile tout
re: fclean all

.PHONY: all clean fclean re
