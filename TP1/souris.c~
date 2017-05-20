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
  if(bouton == GLUT_LEFT_BUTTON && etat == GLUT_UP)
    {
      // stocker des valeurs entre -1 et 1 dans mousePoint.x et mousePoint.y

      int halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
      int halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;

      int mouseXFromHalfWidth = (halfWidth-x);
      int mouseXFromHalfHeight = (halfHeight-y);
      
      mousePoint.x = -(mouseXFromHalfWidth/(float)halfWidth);
      mousePoint.y = (mouseXFromHalfHeight/(float)halfHeight);

      printf("%.3f, %.3f\n", mousePoint.x, mousePoint.y);
    }
  
  glutPostRedisplay();
}
