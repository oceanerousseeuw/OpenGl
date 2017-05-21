INCLUDE= -I /usr/include/GL

LIB= -lglut -lGLU -lGL -lm

CC= gcc

OPTION= -g -Wall -std=c11


tp1:	tp1.o graphique.o clavier.o souris.o menu.o
	$(CC) -o tp1 tp1.o graphique.o clavier.o souris.o $(LIB)

tp1.o:	tp1.c
	$(CC) -c tp1.c $(INCLUDE) $(OPTION)

graphique.o:	graphique.c
	$(CC) -c graphique.c $(INCLUDE) $(OPTION)

clavier.o:	clavier.c
	$(CC) -c clavier.c $(INCLUDE) $(OPTION)

souris.o:	souris.c
	$(CC) -c souris.c $(INCLUDE) $(OPTION)

menu.o:
	$(CC) -c menu.c $(INCLUDE) $(OPTION)

clean:
	rm -r *.o tp1
