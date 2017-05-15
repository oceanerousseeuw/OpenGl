#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "graphique.h"

int main (int argc, char *argv[])
{
  /* initialiser glut */
  glutInit (&argc, argv);
  /* creer la fenetre */
  /*taille de la fenetre*/
  glutInitWindowSize(256,256);
  /*position initiale de la fenetre*/
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);
  /* choix de la fonction de rafraichissement */
  glutDisplayFunc(dessiner);
  /* demarrer la boucle evenementielle */
  glutMainLoop();

  return 0;
}
