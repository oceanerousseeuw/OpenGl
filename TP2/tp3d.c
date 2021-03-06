#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "graphique.h"
#include "touches.h"

/* dimensions initiales de la fen�tre d'affichage */
#define LARGEUR  256
#define HAUTEUR  256
//valeur de placement du repere
float trans_axeZ;
float rot_axeY;
float rot_axeX;
//graduation du repere
float kx;
float ky;
float kz;

/**
 * Fonction d'initialisation des param�tres d'affichage
 */
static void init_screen(void)
{
  //donne la taille ou doit etre affich�e l'image
  //(xbas, ybas, largeur, hauteur)
  glViewport(0, 0, LARGEUR, HAUTEUR);

  //activation de la matrice de transformation geometrique
  glMatrixMode(GL_PROJECTION);

  //on prend la matrice courante
  glLoadIdentity();

  //multiplie la matrice courante par un matrice de perspective
  //(angle douverture de la pyramide, aspect=largeur/hauteur, distance ecran, distance max)
  gluPerspective(60.0, 1, 1, 50);

  //placement du repere
  trans_axeZ = 0.0;
  rot_axeY = 0.0;
  rot_axeX = 0.0;

  //taille des graduations du repere
  kx = 1.0;
  ky = 1.0;
  kz = 1.0;
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
  //creation de la fenetre
  glutInit (&argc, argv);

  glutInitWindowPosition(100, 100); 
  glutInitWindowSize(LARGEUR, HAUTEUR); 

  //suppression des parties cach�es
  glutInitDisplayMode(GLUT_DEPTH);

  glutCreateWindow(argv[0]);

  /* choix de la fonction de rafraichissement */
  glutDisplayFunc(dessiner);
  glutReshapeFunc(retailler);
  glutKeyboardFunc(gerer_clavier);
  glutSpecialUpFunc(gestionClavierSpecial);

  init_screen();

  //ligne avec le glutInitDisplayMode
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  

  return 0;
}


