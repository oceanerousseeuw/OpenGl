#include "clavier.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <math.h>
#include "globals.h"

void gestionClavier(unsigned char touche, int x, int y)
{
  switch(touche)
    {
    case '+':
      pointSize += 1.0;
      break;

    case '-':
      if(pointSize > 1.0)
	pointSize -= 1.0;
      break;
    }
  glutPostRedisplay();
}

void gestionClavierSpecial(int touche, int x, int y)
{
  switch(touche)
    {
    case GLUT_KEY_DOWN :
      mousePoint.y -= 0.1;
      break;
    case GLUT_KEY_LEFT :
      mousePoint.x -= 0.1;
      break;
    case GLUT_KEY_RIGHT :
      mousePoint.x += 0.1;
      break;
    case GLUT_KEY_UP :
      mousePoint.y += 0.1;
      break;
    }
  glutPostRedisplay();
}
