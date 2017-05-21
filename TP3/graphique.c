#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <math.h>

#include "touches.h"
#include "graphique.h"
#include "define.h"

/** 
 * Fonction permettant de dessiner un cube centré sur l'origine 
 * du repère de de taille dimxdimxdim.
 * @param dim la taille du côté du cube.
 */



// cylindre rayon r, hauteur h et nombre facettes nb
void cylindre(float r, float h, int nb)
{
  //First circle
  glBegin(GL_TRIANGLE_FAN);
  for(int i = 0; i < nb*2; i++)
    {
      glVertex3f(cos(i*3.14/nb)*r, sin(i*3.14/nb)*r,0);
    }
  
  glEnd();

  //rects
  glBegin(GL_QUADS);
  for(int i = 0; i < nb*2; i++)
    {
      glVertex3f(cos(i*3.14/nb)*r, sin(i*3.14/nb)*r,0);
      glVertex3f(cos((i+1)*3.14/nb)*r, sin((i+1)*3.14/nb)*r,0);
      glVertex3f(cos((i+1)*3.14/nb)*r, sin((i+1)*3.14/nb)*r,h);
      glVertex3f(cos(i*3.14/nb)*r, sin(i*3.14/nb)*r,h);
    }
  
  glEnd();

  //second circle
  glBegin(GL_TRIANGLE_FAN);
  for(int i = 0; i < nb*2; i++)
    {
      glVertex3f(cos(i*3.14/nb)*r, sin(i*3.14/nb)*r,h);
    }
  
  glEnd();
}

void fuselage()
{
  glColor3f(0,1,0);
  cylindre(0.2, 1, 50);

  //glColor3f(0, 0, 1);
  glTranslatef(0, 0, 1);
  //sphere de rayon 0.2 , avec 50 tranches et 50 quartiers
  //sphere qui arrondi l'avant de l'avion
  glutSolidSphere(0.2,50,50);
  glTranslatef(0, 0, -1);
  //rayon, hauteur, quartiers, tranches
  //cone de l'arriere de l'avion
  glutSolidCone(0.2,-0.2,50,50);
}

//h hauteur, l largeur
void pale(float h, float l)
{
  //on fait un polygone car c'est une forme non connue et plate
  glBegin(GL_POLYGON);
  glVertex3f(l/2, 0, 0);
  glVertex3f(0, h/2, 0);
  glVertex3f(-l/2, 0, 0);
  glVertex3f(0, -h/2, 0);
  glEnd();
}

void helice()
{
  //cone noir pour l'helice
  glColor3f(0, 0, 0);
  glutSolidCone(0.15,0.5,50,50);
  glColor3f(1, 0, 0);

  //on empile les matrices de transformation car on a beaucoup d'objets
  glPushMatrix();
  glTranslatef(0, 0.20, 0.3);
  pale(0.3,0.18);
  //on depile la matrice
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(0, 0-0.20, 0.3);
  pale(0.3,0.18);
  glPopMatrix();
}

void roue(float rayonRoue, float rayonPneu)
{
  glColor3f(1, 0, 0);
  glutSolidTorus(rayonPneu,rayonRoue,50,50);

  glColor3f(0, 0, 1);
  glPushMatrix();

  //cones pour faire les traits dans les roues
  glRotatef(90, 1, 0, 0);
  glutSolidCone(rayonPneu/2, rayonRoue,50,50);
  glRotatef(90, 0, 1, 0);
  glutSolidCone(rayonPneu/2, rayonRoue,50,50);
  glRotatef(90, 0, 1, 0);
  glutSolidCone(rayonPneu/2, rayonRoue,50,50);
  glRotatef(90, 0, 1, 0);
  glutSolidCone(rayonPneu/2, rayonRoue,50,50);
  glPopMatrix();
}


/** 
 * Fonction permettant de dessiner le repère du monde sous 
 * forme d'une croix 3D.
 * @param dim la taille de la ligne représentant un demi-axe.
 */

/*
static void repere(float dim)
{
  glBegin(GL_LINES);
 
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(-dim, 0.0, 0.0);
  glVertex3f( dim, 0.0, 0.0);
  glVertex3f(0.0,-dim, 0.0);
  glVertex3f(0.0, dim, 0.0);
  glVertex3f(0.0, 0.0, -dim);
  glVertex3f(0.0, 0.0,  dim);

  glEnd();
}*/

void ailes(float longueur, float larg)
{
  glPushMatrix();
  //allonger la sphere pour faire les 2 ailes
  glScalef(1,0.05,0.2);
  glutSolidSphere(longueur,50,50);
  
  glPopMatrix();
}


void avion()
{
 /* dessin des objets */
  fuselage();

  glPushMatrix();
  glRotatef(angle_helice,0,0,1);
  glTranslatef(0, 0, 1);
  helice();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.25, -0.2, 0.8);
  glRotatef(90, 0, 1, 0);
  glRotatef(angle_roue, 0, 0, 1);
  roue(0.2,0.05);
  glTranslatef(0,0,-0.5);
  roue(0.2,0.05);
  cylindre(0.05,0.5,50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,0.15,0.5);
  ailes(1,2);
  glPopMatrix();
}
/**
 * Fonction utilisée pour afficher le monde 3D à visualiser. Cette fonction
 * sera appelée à chaque fois qu'un "rafraichissement" de la fenêtre
 * d'affichage sera nécessaire.
 */

void dessiner(void)
{
  /* effacer l'ecran */
  glClearColor(1.0, 1.0, 1.0, 1.0);

  /* raz de la fenetre avec la couleur de fond */
  //utilisation du 2eme buffer image pour plus de fluidité
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  
  glLoadIdentity();
  
  glTranslatef(0, 0, -5+trans_axeZ);
  glRotatef(20+rot_axeY, 0, 1, 0);
  glRotatef(rot_axeX, 1, 0, 0);

  glScalef(kx, ky, kz);
 
  avion();
  
  glFlush();
  //swap des buffers pour que ça aille plus vite
  glutSwapBuffers();
  return;

}

void animer(void)
{
  /*while (angle_helice < 360)
    angle_helice ++;

    angle_helice = 0;*/

  if(helice_active == ON)
    {
      if(angle_helice < 360)
	angle_helice++;
      else
	angle_helice = 0;
    }

  if(roue_active == ON)
    {
      if(angle_roue < 360)
	angle_roue++;
      else
	angle_roue = 0;
    }
  glutPostRedisplay();
}

extern void retailler(GLsizei largeur, GLsizei hauteur)
{
  int cote = hauteur;
  if(hauteur > largeur)
    cote = largeur;
  
  glViewport(largeur/2 - cote/2,hauteur/2 -cote/2, cote, cote);

  glMatrixMode(GL_PROJECTION);
  
  glutPostRedisplay();
}
