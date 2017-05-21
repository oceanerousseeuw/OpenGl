#ifndef _TOUCHES_H
#define _TOUCHES_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

extern float trans_axeZ;
extern float rot_axeY;
extern float rot_axeX;

extern float kx;
extern float ky;
extern float kz;

void gerer_clavier(unsigned char touche, int x, int y);

void gestionClavierSpecial(int touche, int x, int y);

#endif
