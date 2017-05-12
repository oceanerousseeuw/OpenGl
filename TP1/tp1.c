#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

void dessiner(void)
{
  return;
}

int main (int argc, char *argv[])
{
  /* initialiser glut */
  glutInit (&argc, argv);
  /* creer la fenetre */
  glutCreateWindow(argv[0]);
  /* choix de la fonction de rafraichissement */
  glutDisplayFunc(dessiner);
  /* demarrer la boucle evenementielle */
  glutMainLoop();
}
