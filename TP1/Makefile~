#definition des dossiers d'inclusion des bibliothèques .h
INCLUDE= -I /usr/include/GL

#definition des librairies a utiliser lors de l'etape d'edition de liens
LIB= -lglut -lGLU -lGL -lm

#definition du compilateur a utiliser
CC=g++

#definition des options de compilation a utiliser
#-g en vue d'autoriser l'utilisation du debugger
#-Wall affiche le max de messages d'erreurs
OPTION= -g -Wall -Wextra -std=c++11

tp1:	tp1.o graphique.o 
	$(CC) -o tp1 tp1.o $(LIB)

tp1.o:	tp1.cpp
	$(CC) -c tp1.cpp $(INCLUDE) $(OPTION)

graphique.o:	graphique.cpp
	$(CC) -c graphique.cpp $(INCLUDE) $(OPTION)

clean:
	rm -r *.o tp1
