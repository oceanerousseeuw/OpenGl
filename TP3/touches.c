#include "touches.h"
#include "graphique.h"
#include "define.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

void gerer_clavier(unsigned char touche, int x, int y)
{
  if(touche == '-')
    trans_axeZ -= 0.1;
  else if(touche == '+')
    trans_axeZ += 0.1;

  if(touche == '6')
    rot_axeY += 10;
  else if(touche == '4')
    rot_axeY -= 10;

  if(touche == '8')
    rot_axeX += 10;
  else if(touche == '2')
    rot_axeX -= 10;

  if(touche == 'h')
    {
      if(helice_active == ON)
	helice_active = OFF;
      else
	helice_active = ON;
    }

  if(touche == 'r')
    {
      if(roue_active == ON)
	roue_active = OFF;
      else
	roue_active = ON;
    }
  glutPostRedisplay();
}



void gestionClavierSpecial(int touche, int x, int y)
{
  switch(touche)
    {
    case GLUT_KEY_DOWN :
      ky *= 0.5;
      break;
    case GLUT_KEY_LEFT :
      kx *= 0.5;
      break;
    case GLUT_KEY_RIGHT :
      kx *= 2;
      break;
    case GLUT_KEY_UP :
      ky *= 2;
      break;
    case GLUT_KEY_PAGE_UP:
      kz *= 2;
      break;
    case GLUT_KEY_PAGE_DOWN:
      kz *= 0.5;
      break;
    }
  glutPostRedisplay();
}
