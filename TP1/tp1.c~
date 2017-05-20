#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include "graphique.h"
#include "clavier.h"
#include "geometrie.h"
#include "souris.h"
#include "menu.h"

float pointSize;
float lineWidth;

Point2D mousePoint;

int main(int argc, char *argv[])
{
  pointSize = 1.0;
  mousePoint.x = UNDEFINED;
  mousePoint.y = UNDEFINED;
  
  // init glut
  glutInit (&argc, argv);

  glutInitWindowSize(350,350);
  glutInitWindowPosition(100,100);
 
  //creer la fenetre
  glutCreateWindow(argv[0]);

  // choix fonction refresh
  glutDisplayFunc(dessiner);
  glutKeyboardFunc(gestionClavier);
  glutMouseFunc(mousePos);
  glutSpecialUpFunc(gestionClavierSpecial);
  
  //demarrer la boucle evenementielle
  glutMainLoop();
  return 0;
}
