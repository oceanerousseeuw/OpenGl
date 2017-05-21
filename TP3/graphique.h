#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

extern int angle_helice;
extern int helice_active;
extern int angle_roue;
extern int roue_active;

extern void dessiner(void);
extern void retailler(GLsizei largeur, GLsizei hauteur);
void cylindre(float r, float h, int nb);
void fuselage();
void pale(float h, float l);
void helice();
void roue(float rayonRoue, float rayonPneu);
void animer(void);
