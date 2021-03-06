#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <math.h>
#include "graphique.h"
#include "globals.h"

void dessiner(void)
{
  //changer la couleur de la fenetre
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  //initialise le diametre du point et de la ligne
  glPointSize(pointSize);
  glLineWidth(pointSize);


  //initilisation d'un point de couleur rouge
  glBegin(GL_POINTS);
  glColor3f(1, 0, 0);
  //il se dessine au niveau ou on clique
  glVertex2f(mousePoint.x, mousePoint.y);
  glEnd();

  //on dessine les points en cercle
  glBegin(GL_POINTS);
  glColor3f(1,0,0);
  //on dessine 64 points
  for(int i = 0; i < 64; i++)
    {
      glVertex2f(cos(i*3.14/32)*0.25-0.5, sin(i*3.14/32)*0.25);
    }
  //si on veut en dessine moins, change le i<64 et les /32 de cos et sin
  glEnd();

  //dessine le carré
  glBegin(GL_POLYGON);
  glColor3f(0, 0, 1);
  glVertex2d(0.0, 0.0);
  glVertex2d(0.5, 0.0);
  glVertex2d(0.5, 0.5);
  glVertex2d(0.0, 0.5);
  glEnd();

  //forcer l execution
  glFlush();
  return;
}
