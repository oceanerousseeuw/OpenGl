#include "touches.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

void gerer_clavier(unsigned char touche, int x, int y)
{
  //on eloigne
  if(touche == '-')
    trans_axeZ -= 0.1;
  //on rapproche
  else if(touche == '+')
    trans_axeZ += 0.1;

  //on tourne vers la droite
  if(touche == '6')
    rot_axeY += 10;
  //on tourne vers la gauche
  else if(touche == '4')
    rot_axeY -= 10;

  //on tourne vers le haut
  if(touche == '8')
    rot_axeX += 10;
  //on tourne vers le bas
  else if(touche == '2')
    rot_axeX -= 10;

  //mise a jour de l'image
  glutPostRedisplay();
}



void gestionClavierSpecial(int touche, int x, int y)
{
  switch(touche)
    {
      //on divise la largeur du cube par 2
    case GLUT_KEY_LEFT :
      kx *= 0.5;
      break;
      //on grossit la largeur du cube par 2
    case GLUT_KEY_RIGHT :
      kx *= 2;
      break;
      //on agrandit la hauteur du cube par 2
      case GLUT_KEY_UP :
      ky *= 2;
      break;
      //on divise la hateur par 2
    case GLUT_KEY_DOWN :
      ky *= 0.5;
      break;/*
    case GLUT_KEY_PAGE_UP:
      kz *= 2;
      break;
    case GLUT_KEY_PAGE_DOWN:
      kz *= 0.5;
      break;*/
    }
  glutPostRedisplay();
}
