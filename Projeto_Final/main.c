#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp_loader.h"
#include "texture.h"
#include "draws.h"

#define WIDTH 1360
#define HEIGHT 780
#define LENGTH 1.0

extern GLuint texture_nomes [80];
extern int VariaDiaNoite;
extern GLfloat v[8][3];
extern float posx, posz, posy, angle, bottom;

void init(void);
void keyboard (unsigned char key, int x, int y);
void idle();

extern float trans_x;
extern float trans_x_SolLua;
extern float trans_y;



int zera= 0;

void idle(){ //
    trans_x= 3*sin(0.0001* glutGet(GLUT_ELAPSED_TIME));
    trans_x_SolLua= 19*sin(0.0001* glutGet(GLUT_ELAPSED_TIME));
    trans_y= 17*cos(0.0001* glutGet(GLUT_ELAPSED_TIME));
    glutPostRedisplay();

}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("Minecraft");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();

    return 0;
}

void init(void){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    const float lenght = 1.0;
    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -lenght;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = lenght;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -lenght;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = lenght;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = lenght;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = -lenght;

    glClearColor(0.53, 0.81, 0.98, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)WIDTH / (float)HEIGHT, 1.0f, 100.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glGenTextures(80, texture_nomes);
    makeTexture();

}

void keyboard(unsigned char key, int x, int y){
    static float posx= 0.0, posz= -5.0, angle= 0.0;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) WIDTH/ (float)HEIGHT, 1.0f, 100.0f);
    switch(key){
        case 27:
            exit(0);
        break;
        case 'w':
        case 'W':
            posz += 0.1*cos(M_PI*angle/180.0)*10;
            posx += 0.1*sin(M_PI*angle/180.0)*10;

        break;
        case 's':
        case 'S':
            posz -= 0.1*cos(M_PI*angle/180.0)*10;
            posx -= 0.1*sin(M_PI*angle/180.0)*10;

        break;
        case 'q':
        case 'Q':
            posz += -0.1*sin(M_PI*angle/180.0)*10;
            posx += 0.1*cos(M_PI*angle/180.0)*10;
        break;

        case 'e':
        case 'E':
            posz -= -0.1*sin(M_PI*angle/180.0)*10;
            posx -= 0.1*cos(M_PI*angle/180.0)*10;
        break;
        case 'a':
        case 'A':
            angle += 5;
        break;
        case 'd':
        case 'D':
            angle -= 5;
        break;

        case 'r':
        case 'R':
            posy -= -0.1*sin(M_PI*angle/180.0)*10;

        break;

        case 't':
        case 'T':
             posy += -0.1*sin(M_PI*angle/180.0)*10;
        break;

    }
    glRotatef(-angle, 0.0, 1.0, 0.0);
    glTranslatef(posx, 0.0, posz);

    glutPostRedisplay();
}



