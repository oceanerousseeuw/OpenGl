#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "graphique.h"

/* dimensions initiales de la fen�tre d'affichage */
#define LARGEUR  256
#define HAUTEUR  256


/**
 * Fonction d'initialisation des param�tres d'affichage
 */
static void init_screen(void)
{

}


/**
 * Fonction principale qui cr�e et initialise la fen�tre
 * d'affichage et lance la boucle d'affichage Glut.
 * @param argc le nombre d'argument sur la ligne de commande
 * @param argv une table de cha�ne de caract�res contenant chacun
 * des arguments de la ligne de commande.
 */
int main (int argc, char *argv[])
{

  glutInit (&argc, argv);

  glutInitWindowPosition(100, 100); 
  glutInitWindowSize(LARGEUR, HAUTEUR); 

  glutInitDisplayMode(GLUT_DEPTH);

  glutCreateWindow(argv[0]);

  /* choix de la fonction de rafraichissement */
  glutDisplayFunc(dessiner);


  init_screen();

  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  

  return 0;
}


