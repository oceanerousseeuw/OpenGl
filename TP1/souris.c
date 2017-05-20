#include "souris.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include "geometrie.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

void mousePos(int bouton, int etat, int x, int y)
{
  //si on appuie sur le bouton gauche et qu'il est appuyé
  if(bouton == GLUT_LEFT_BUTTON && etat == GLUT_UP)
    {
      // stocker des valeurs entre -1 et 1 dans mousePoint.x et mousePoint.y

      //recuperer la taille de la fenetre et la diviser par deux
      //pour trouver le milieu de la fenetre
      int halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
      int halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;

      //on compte la position du point depuis le milieu de la fenetre
      int mouseXFromHalfWidth = (halfWidth-x);
      int mouseXFromHalfHeight = (halfHeight-y);

      //on convertit la position du point pour qu'il rentre dans la fenetre
      //qui va de -1 a 1 pour x et y
      mousePoint.x = -(mouseXFromHalfWidth/(float)halfWidth);
      mousePoint.y = (mouseXFromHalfHeight/(float)halfHeight);

      printf("%.3f, %.3f\n", mousePoint.x, mousePoint.y);
    }
  
  glutPostRedisplay();
}
