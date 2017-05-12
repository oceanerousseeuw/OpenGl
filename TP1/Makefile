#definition des dossiers d'inclusion des bibliothèques .h
INCLUDE= -I /usr/include/GL

#definition des librairies a utiliser lors de l'etape d'edition de liens
LIB= -lglut -lGLU -lGL -lm

#definition du compilateur a utiliser
CC=gcc

#definition des options de compilation a utiliser
#-g en vue d'autoriser l'utilisation du debugger
#-Wall affiche le max de messages d'erreurs
OPTION= -g -Wall -Wextra

tp1:	tp1.o
	$(CC) -o tp1 tp1.o $(LIB)

tp1.o:	tp1.c
	$(CC) -c tp1.c $(INCLUDE) $(OPTION)

clean:
	rm -r *.o tp1
