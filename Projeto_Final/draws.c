#include "draws.h"

#include <math.h>

GLuint texture_nomes [90];
int i, poker=0;


//------move marco------
float rot_rate = 0;
float trans_rate = 0,ytrans_rate = 0,transl_rate = 0;
float  move = 1.15;
//-------------

GLint faces[6][4] = {
    {0,1,2,3}, {3,2,6,7}, {7,6,5,4},
    {4,5,1,0}, {5,6,2,1}, {7,4,0,3}
};

GLfloat v[8][3];

int VariaDiaNoite=0;
float trans_x;
float trans_y;
float trans_x_SolLua;

void drawCube(){

    for(i = 0; i < 6; i++){
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
    }

}

//****************************************
void drawMatriz(float tx, float ty){
	glPushMatrix();
    glTranslatef(tx, ty, 0.0);
    drawCube();
	glPopMatrix();
}

//***************************************************FORMAS********************************************************

//Ilha - Solo
static void desenhaSoloIlha(){
    int i, j;
    glPushMatrix();
        glScalef(1, 1, 1);
        glTranslatef(0, 0, -1.0);
        for(i= 0; i<4; i++){
            glTranslatef(-32, 0, 1);

            for(j=0; j<16; j++){

                if(i%2==1 && j== 0 || i==2 && j==0  ||  i==1 && j==1 ||  i==2 && j==1){
                    glPushMatrix();
                        glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);
                        glTranslatef(2, -0.1, 0);
                        drawCube();
                    glPopMatrix();

                    glTranslatef(2, 0, 0);
                }

                  else{
                    glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);
                    glTranslatef(2, 0, 0);
                    drawCube();

                }
            }
        }

    glPopMatrix();

//casa
    glPushMatrix();
        glScalef(1, 1, 1);

        for(i= 0; i<16; i++){
            glTranslatef(-32, 0, -2);

            for(j=0; j<16; j++){
                if(i%2==0 && j%2==0 || i+j %2 ==1)
                  glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);
                else if(j%3==0)
                    glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);
                else if(i%3==0)
                    glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);
                else
                    glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);


                if(i%2==1 && j== 0 || i==2 && j==0  ||  i==6 && j==0 ||  i==7 && j==0 ){

                        glPushMatrix();
                            glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);
                            glTranslatef(2, -0.1, 0);

                            drawCube();
                        glPopMatrix();
                        glTranslatef(2, 0, 0);
                }
                else{
                    glTranslatef(2, 0, 0);
                    drawCube();

                }
            }
        }
    glPopMatrix();
}

//Arvores
static void desenhaArvore(){
        glPushMatrix(); // troco arvore
                glBindTexture(GL_TEXTURE_2D, texture_nomes[0]);
                glTranslatef(-4, 3.5, -12);
                glScalef(0.70, 0.70, 0.70);
                drawCube();

                glTranslatef(0, -2, 0);
                drawCube();

                glTranslatef(0, -2, 0);
                drawCube();


        glPopMatrix();


        glPushMatrix();// folhas arvore BASE
                glBindTexture(GL_TEXTURE_2D, texture_nomes[2]);
                glTranslatef(-4, 5, -12);
                glScalef(3.0, 0.8, 3.0);
                drawCube();
        glPopMatrix();

        glPushMatrix();// folhas arvore
                glBindTexture(GL_TEXTURE_2D, texture_nomes[2]);
                glTranslatef(-3.8, 6.5, -12);
                glScalef(2, 0.8, 2);
                drawCube();
        glPopMatrix();


        glPushMatrix();// folhas topo
                glBindTexture(GL_TEXTURE_2D, texture_nomes[2]);
                glTranslatef(-3.8, 7.5, -12);
                glScalef(1, 0.8, 1);
                drawCube();
        glPopMatrix();
}

//Montanha
static void desenhaMontanha(){
    int i, j;
    glPushMatrix();
        glScalef(1, 1, 1);
        glTranslatef(-30, 2,-32);
        for(i=0; i<3; i++){
                glTranslatef(-3, 0, 2);
            for(j=0; j<2; j++){
                glBindTexture(GL_TEXTURE_2D, texture_nomes[1]);
                glTranslatef(2, 0, 0);
                drawCube();
            }
        }
    glPopMatrix();
}
//Chao1
static void desenhaTerra2 (){
    int i, j;
    glPushMatrix();
        glScalef(1, 1, 1);
        glTranslatef(32, -0.1,-80);
        for(i=0; i<64; i++){
                glTranslatef(-1600, 0, 2);
            for(j=0; j<800; j++){
                glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);
                glTranslatef(2, 0, 0);
                drawCube();
            }
        }
    glPopMatrix();
}

//Ahs
static void desenhaAhs(){
    glPushMatrix(); //rosto
        glTranslatef(-6, 4.2, -3.28);
        glScalef(0.4, 0.4, 0.4);
        //glBindTexture(GL_TEXTURE_2D, texture_nomes[13]);
        int i;
    for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[13]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[20]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[21]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[22]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[23]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[24]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix(); //camisa
        glTranslatef(-6, 3.3, -3.28);
        glScalef(0.5, 0.5, 0.2);

        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[15]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[26]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[27]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[22]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[25]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[24]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }

    glPopMatrix();


    glPushMatrix(); //cal�a
        glTranslatef(-6, 2.1, -3.28);
        glScalef(0.5, 0.7, 0.2);
         for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[16]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[34]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[32]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[30]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[33]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[24]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix(); //Bra�o direito
        glTranslatef(-5.27, 3.1, -3.40);
        glRotatef(30.0, 1.0, 0.0, 0.0);
        glScalef(0.23, 0.7, 0.23);


        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[14]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[29]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[31]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[30]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[28]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[24]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix(); //Bra�o esquerda
        glTranslatef(-6.72, 3.1, -3.28);
        glRotatef(30.0, 1.0, 0.0, 0.0);
        glScalef(0.23, 0.7, 0.23);
        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[14]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[29]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[31]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[30]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[28]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[24]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();
}

//Pikachu
static void desenhaPikachu(){
    int i;

    glPushMatrix(); //olhera 1
        glTranslatef(-5.65, 2.2, -3.95);
        glScalef(0.05, 0.1, 0.03);
        glRotatef(-180.0, 0.0, -2.0,0.0);

        for(i = 0; i <6; i++){
            if(i==4){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[53]);
            }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
            }
            glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3fv(&v[faces[i][0]][0]);

                glTexCoord2f(0.0, 1.0);
                glVertex3fv(&v[faces[i][1]][0]);

                glTexCoord2f(1.0, 1.0);
                glVertex3fv(&v[faces[i][2]][0]);

                glTexCoord2f(1.0, 0.0);
                glVertex3fv(&v[faces[i][3]][0]);
            glEnd();
            glPopMatrix();
    }
    glPopMatrix();


     glPushMatrix(); //Orelha 2
        glTranslatef(-5.5, 2.2, -3.95);
        glScalef(0.05, 0.1, 0.03);
        glRotatef(-180.0, 0.0, -2.0,0.0);
                for(i = 0; i <6; i++){
            if(i==4){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[53]);
            }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
            }
            glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3fv(&v[faces[i][0]][0]);

                glTexCoord2f(0.0, 1.0);
                glVertex3fv(&v[faces[i][1]][0]);

                glTexCoord2f(1.0, 1.0);
                glVertex3fv(&v[faces[i][2]][0]);

                glTexCoord2f(1.0, 0.0);
                glVertex3fv(&v[faces[i][3]][0]);
            glEnd();
            glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix(); //cabeça
        glScalef(0.2, 0.2, 0.3);
         glTranslatef(-28.0, 9.5, -14);
        glRotatef(-180.0, 0.0, -2.0,0.0);

        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[51]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[54]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();


glPushMatrix(); //pata 1
        glTranslatef(-5.65, 1.7, -3.95);
        glScalef(0.05, 0.099, 0.04);
        glRotatef(-180.0, 0.0, -2.0,0.0);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        drawCube();
    glPopMatrix();

       glPushMatrix(); //pata 2
        glTranslatef(-5.5, 1.7, -3.95);
        glScalef(0.05, 0.099, 0.04);
        glRotatef(-180.0, 0.0, -2.0,0.0);
                glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        drawCube();
    glPopMatrix();


    glPushMatrix(); //pata 3
        glTranslatef(-5.5, 1.7, -4.4);
        glScalef(0.05, 0.099, 0.04);
        glRotatef(-180.0, 0.0, -2.0,0.0);
                glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        drawCube();
    glPopMatrix();


    glPushMatrix(); //pata 4

        glTranslatef(-5.7, 1.7, -4.4);
        glScalef(0.05, 0.099, 0.04);
        glRotatef(-180.0, 0.0, -2.0,0.0);
              glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        drawCube();
    glPopMatrix();


    glPushMatrix(); //raboParte1
        glTranslatef(-5.25, 1.9, -4.5);
        glScalef(0.2, 0.1, 0.02);
        glRotatef(-180.0, 0.0, -2.0,0.0);
        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix(); //raboParte2
        glTranslatef(-5.0, 2.2, -4.5);
        glScalef(0.3, 0.2, 0.02);
        glRotatef(-180.0, 0.0, -2.0,0.0);
        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();


}

//Miltank
static void desenhaMiltank(){

    glPushMatrix();//Chifre 1
        glScalef(0.4, 0.4, 0.4);
        glTranslatef(-16, 9.5, -9);
        glScaled(0.1, 0.50, 0.1);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[19]);
        drawCube();
    glPopMatrix();

    glPushMatrix();//Chifre 2
        glScalef(0.4, 0.4, 0.4);
        glTranslatef(-14, 9.5, -9);
        glScaled(0.1, 0.50, 0.1);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[19]);
        drawCube();
    glPopMatrix();

     glPushMatrix(); //cabeça

        glScalef(0.4, 0.4, 0.4);
        glTranslatef(-15, 8.5, -9);
        glRotatef(-180.0, 0.0, -2.0,0.0);

        int i;
        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[10]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[37]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[35]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[36]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix(); //corpo
    glScalef(0.6, 0.5, 0.9);
        glTranslatef(-10, 5.0, -5);
        glRotatef(-180.0, 0.0, -2.0,0.0);

        for(i = 0; i <6; i++){
        if(i==4){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[39]);
        }else if (i==2){
         glBindTexture(GL_TEXTURE_2D, texture_nomes[40]);
        }else if(i==5){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[42]);
        }else if(i==1){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[43]);
        }else if(i==0){
        glBindTexture(GL_TEXTURE_2D, texture_nomes[41]);
        }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 1.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(1.0, 1.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(1.0, 0.0);
            glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix(); //pata 1
        glTranslatef(-5.65, 1.7, -3.95);
        glScalef(0.2, 0.32, 0.2);
        glRotatef(-180.0, 0.0, -2.0,0.0);

        for(i = 0; i <6; i++){
            if(i==4){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[44]);
            }else if (i==2){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[47]);
            }else if(i==5){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[45]);
            }else if(i==1){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[43]);
            }else if(i==0){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[46]);
            }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
            }
            glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3fv(&v[faces[i][0]][0]);

                glTexCoord2f(0.0, 1.0);
                glVertex3fv(&v[faces[i][1]][0]);

                glTexCoord2f(1.0, 1.0);
                glVertex3fv(&v[faces[i][2]][0]);

                glTexCoord2f(1.0, 0.0);
                glVertex3fv(&v[faces[i][3]][0]);
            glEnd();
            glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix(); //pata 2
        glTranslatef(-6.32, 1.7, -3.95);
        glScalef(0.2, 0.32, 0.2);
        glRotatef(-180.0, 0.0, -2.0,0.0);
                for(i = 0; i <6; i++){
            if(i==4){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[44]);
            }else if (i==2){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[47]);
            }else if(i==5){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[45]);
            }else if(i==1){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[43]);
            }else if(i==0){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[46]);
            }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
            }
            glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3fv(&v[faces[i][0]][0]);

                glTexCoord2f(0.0, 1.0);
                glVertex3fv(&v[faces[i][1]][0]);

                glTexCoord2f(1.0, 1.0);
                glVertex3fv(&v[faces[i][2]][0]);

                glTexCoord2f(1.0, 0.0);
                glVertex3fv(&v[faces[i][3]][0]);
            glEnd();
            glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix(); //pata 3
        glTranslatef(-5.65, 1.7, -5.10);
        glScalef(0.2, 0.32, 0.2);
        glRotatef(-180.0, 0.0, -2.0,0.0);
                for(i = 0; i <6; i++){
            if(i==4){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[44]);
            }else if (i==2){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[47]);
            }else if(i==5){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[45]);
            }else if(i==1){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[43]);
            }else if(i==0){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[46]);
            }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
            }
            glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3fv(&v[faces[i][0]][0]);

                glTexCoord2f(0.0, 1.0);
                glVertex3fv(&v[faces[i][1]][0]);

                glTexCoord2f(1.0, 1.0);
                glVertex3fv(&v[faces[i][2]][0]);

                glTexCoord2f(1.0, 0.0);
                glVertex3fv(&v[faces[i][3]][0]);
            glEnd();
            glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix(); //pata 4
        glTranslatef(-6.32, 1.7, -5.10);
        glScalef(0.2, 0.32, 0.2);
        glRotatef(-180.0, 0.0, -2.0,0.0);
                for(i = 0; i <6; i++){
            if(i==4){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[44]);
            }else if (i==2){
             glBindTexture(GL_TEXTURE_2D, texture_nomes[47]);
            }else if(i==5){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[45]);
            }else if(i==1){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[43]);
            }else if(i==0){
            glBindTexture(GL_TEXTURE_2D, texture_nomes[46]);
            }else{
            glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
            }
            glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3fv(&v[faces[i][0]][0]);

                glTexCoord2f(0.0, 1.0);
                glVertex3fv(&v[faces[i][1]][0]);

                glTexCoord2f(1.0, 1.0);
                glVertex3fv(&v[faces[i][2]][0]);

                glTexCoord2f(1.0, 0.0);
                glVertex3fv(&v[faces[i][3]][0]);
            glEnd();
            glPopMatrix();
    }
    glPopMatrix();


}
//Nuvem
 static void desenhaNuvem(){
    int i , j;
        glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);
        glTranslatef(-70, 30, 0);
        glScalef(1.0, 0.3, 1.0);
    for(i=0; i< 3; i++){
        glTranslatef(0, 0, -1.0);
        for(j=0; j<3; j++){
            if(i==j)
                glTranslatef(5, 0, -5);
            else
                glTranslatef(i+3, 0, j+4);

            drawCube();

        }

   }
}

//Lua ou Sol
static void desenhaSol(){
    glPushMatrix();
        glTranslatef(-40, 1, -75);
        glScalef(3.0, 3.0, 1.0);
        drawCube();
    glPopMatrix();
}

//Ginasio
static void desenhaGinasio(){
// Parte Frente
  //pilar 1
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-80.0, 2.0, -10.0);
      glScalef(20.0, 8.0, 1.0);
      drawCube();
   glPopMatrix();

   // telha 1

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-80.0, 10.2, -10.0);
      glScalef(21.0, 0.35, 1.0);
      drawCube();
   glPopMatrix();

    //pilar do 2

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-60.0, 3.0, -12.0);
      glScalef(1.0, 8.5, 1.0);
      drawCube();
  glPopMatrix();

  //Telha 2
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-58.0, 11.2, -12.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 3

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-59.0, 4.0, -14.0);
      glScalef(1.0, 9.5, 1.0);
      drawCube();
  glPopMatrix();

  //telha 3
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-57.0, 13.2, -14.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 4

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-58.0, 5.0, -16.0);
      glScalef(1.0, 10.5, 1.0);
      drawCube();
  glPopMatrix();

  // telha 4
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-56.0, 15.2, -16.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  // pilar 5
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-57.0, 12.0, -21.0);
      glScalef(1.0, 5.5, 4.0);
      drawCube();
   glPopMatrix();

   //telha 5
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-54.0, 17.2, -21.0);
      glScalef(2.0, 0.35, 4.0);
      drawCube();
   glPopMatrix();

   // pilar 6

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-58.0, 5.0, -26.0);
      glScalef(1.0, 10.5, 1.0);
      drawCube();
  glPopMatrix();

  // telha 6

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-56.0, 15.2, -26.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 7

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-59.0, 4.0, -28.0);
      glScalef(1.0, 9.5, 1.0);
      drawCube();
  glPopMatrix();

  //telha 7
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-57.0, 13.2, -28.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 8

    glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-60.0, 3.0, -30.0);
      glScalef(1.0, 8.5, 1.0);
      drawCube();
  glPopMatrix();

  //telha 8

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-58.0, 11.2, -30.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 9

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-80.0, 2.0, -32.0);
      glScalef(20.0, 8.0, 1.0);
      drawCube();
   glPopMatrix();

   //telha 9
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-80.0, 10.2, -32.0);
      glScalef(21.0, 0.35, 1.0);
      drawCube();
   glPopMatrix();

// Parte de Tras

  //Pilar 2
     glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-99.0, 3.0, -12.0);
      glScalef(1.0, 8.5, 1.0);
      drawCube();
  glPopMatrix();

  //Telha 2
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-98.0, 11.2, -12.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 3

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-99.0, 4.0, -14.0);
      glScalef(1.0, 9.5, 1.0);
      drawCube();
  glPopMatrix();

  //telha 3
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-98.0, 13.2, -14.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 4

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-99.0, 5.0, -16.0);
      glScalef(1.0, 10.5, 1.0);
      drawCube();
  glPopMatrix();

  // telha 4
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-98.0, 15.2, -16.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  // pilar 5
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-99.0, 6.0, -21.0);
      glScalef(1.0, 11.5, 4.0);
      drawCube();
   glPopMatrix();

   //telha 5
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-98.0, 17.2, -21.0);
      glScalef(2.0, 0.35, 4.0);
      drawCube();
   glPopMatrix();

   // pilar 6

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-99.0, 5.0, -26.0);
      glScalef(1.0, 10.5, 1.0);
      drawCube();
  glPopMatrix();

  // telha 6

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-98.0, 15.2, -26.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 7

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-99.0, 4.0, -28.0);
      glScalef(1.0, 9.5, 1.0);
      drawCube();
  glPopMatrix();

  //telha 7
  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-98.0, 13.2, -28.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

  //pilar 8

    glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-99.0, 3.0, -30.0);
      glScalef(1.0, 8.5, 1.0);
      drawCube();
  glPopMatrix();

  //telha 8

  glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-98.0, 11.2, -30.0);
      glScalef(1.0, 0.35, 1.0);
      drawCube();
  glPopMatrix();

// pokebola

   //base
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);
      glTranslatef(-56.0, 8.0, -21.0);
      glScalef(1.0, 0.49, 1.5);
      drawCube();
   glPopMatrix();

   //base 2
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);
      glTranslatef(-56.0, 9.0, -21.0);
      glScalef(1.0, 0.49, 2.0);
      drawCube();
   glPopMatrix();

   //base 3 meio

      glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
      glTranslatef(-56.0, 10.0, -21.0);
      glScalef(1.0, 0.49, 0.85);
      drawCube();
   glPopMatrix();

   // base 3 lateral 1

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);
      glTranslatef(-56.0, 10.0, -19.5);
      glScalef(1.0, 0.49, 0.95);
      drawCube();
   glPopMatrix();

   // base 3 lateral 2

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);
      glTranslatef(-56.0, 10.0, -22.5);
      glScalef(1.0, 0.49, 0.95);
      drawCube();
   glPopMatrix();

   //base 4 meio

      glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);
      glTranslatef(-56.0, 11.0, -21.0);
      glScalef(1.0, 0.49, 0.85);
      drawCube();
   glPopMatrix();

   // base 4 lateral 1

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
      glTranslatef(-56.0, 11.0, -19.5);
      glScalef(1.0, 0.49, 0.95);
      drawCube();
   glPopMatrix();

   // base 4 lateral 2

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
      glTranslatef(-56.0, 11.0, -22.5);
      glScalef(1.0, 0.49, 0.95);
      drawCube();
   glPopMatrix();


   //base 5 meio

      glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);
      glTranslatef(-56.0, 12.0, -21.0);
      glScalef(1.0, 0.49, 0.85);
      drawCube();
   glPopMatrix();

   // base 5 lateral 1

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-56.0, 12.0, -19.5);
      glScalef(1.0, 0.49, 0.95);
      drawCube();
   glPopMatrix();

   // base 5 lateral 2

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-56.0, 12.0, -22.5);
      glScalef(1.0, 0.49, 0.95);
      drawCube();
   glPopMatrix();

   //base 6
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-56.0, 13.0, -21.0);
      glScalef(1.0, 0.49, 2.0);
      drawCube();
   glPopMatrix();

   //base 7
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);
      glTranslatef(-56.0, 14.0, -21.0);
      glScalef(1.0, 0.49, 1.5);
      drawCube();
   glPopMatrix();

//detalhes
   //1
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-55.5, 5.5, -17.45);
      glScalef(0.45, 11.45, 0.40);
      drawCube();
   glPopMatrix();

   //2
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-55.5, 5.5, -24.45);
      glScalef(0.45, 11.45, 0.40);
      drawCube();
   glPopMatrix();

   //3

   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-56.0, 7.0, -21.0);
      glScalef(1.0, 0.49, 1.5);
      drawCube();
   glPopMatrix();

   //4
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-56.0, 6.0, -21.0);
      glScalef(4.0, 0.49, 3.0);
      drawCube();
   glPopMatrix();

   //5
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-57.0, 12.0, -16.45);
      glScalef(0.45, 3.5, 0.40);
      drawCube();
   glPopMatrix();

   //6
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-58.0, 11.5, -14.45);
      glScalef(0.45, 1.5, 0.40);
      drawCube();
   glPopMatrix();

   //7
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-59.0, 10.5, -12.45);
      glScalef(0.45, 0.5, 0.45);
      drawCube();
   glPopMatrix();

   //8
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
       glTranslatef(-56.9, 6.0, -16.45);
      glScalef(0.2, 0.49, 1.5);
      drawCube();
   glPopMatrix();

    //9
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-57.9, 5.0, -14.45);
      glScalef(0.2, 0.49, 1.5);
      drawCube();
   glPopMatrix();

   //10
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-58.9, 4.0, -12.45);
      glScalef(0.2, 0.49, 1.5);
      drawCube();
   glPopMatrix();

   //11
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-59.6, 3.0, -9.99);
      glScalef(0.2, 0.49, 1.0);
      drawCube();
   glPopMatrix();


   //12
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-57.0, 11.5, -25.2);
      glScalef(0.45, 3.5, 0.40);
      drawCube();
   glPopMatrix();

  //13
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-58.0, 11.5, -27.4);
      glScalef(0.45, 1.5, 0.40);
      drawCube();
   glPopMatrix();

   //14
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-59., 10.5, -29.4);
      glScalef(0.45, 0.5, 0.40);
      drawCube();
   glPopMatrix();

   //15
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-56.9, 6.0, -25.0);
      glScalef(0.2, 0.49, 2.0);
      drawCube();
   glPopMatrix();

    //16
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-57.9, 5.0, -28.0);
      glScalef(0.2, 0.49, 1.1);
      drawCube();
   glPopMatrix();

  //17
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);
      glTranslatef(-58.9, 4.0, -30.0);
      glScalef(0.2, 0.49, 1.0);
      drawCube();
   glPopMatrix();

   //18
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);

      glTranslatef(-59.6, 3.0, -32.0);
      glScalef(0.2, 0.49, 0.8);
      drawCube();
   glPopMatrix();

   //passarela
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);
      glTranslatef(-49.0, -3.0, -21.0);
      glScalef(10, 0.5, 4.0);
      drawCube();
   glPopMatrix();


   //Chao
   glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture_nomes[55]);
      glTranslatef(-80.1, -3.0, -21.0);
      glScalef(20.01, 0.5, 11.5);
      drawCube();
   glPopMatrix();
}
void bracotelaPokebola() {
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_nomes[59]);
    glTranslatef(-1, -0.90, -2.1);
    glRotatef(145.0, 2.0, 0.0, 0.0);
    glScalef(0.5, 0.0, 0.4);
    drawCube();
    glPopMatrix();
}

//**************************************************************************************************************
void bracotela() {
glPushMatrix();
    glTranslatef(0.70, -0.50, -2.0);
    glRotatef(145.0, 1.0, 0.0, 0.0);
    glScalef(0.15, 0.3, 0.15);
   if( poker==1){
         bracotelaPokebola();
   }
//Braço
    for(i = 0; i <6; i++) {
        if(i==4) {
            glBindTexture(GL_TEXTURE_2D, texture_nomes[14]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, texture_nomes[29]);
        } else if(i==5) {
            glBindTexture(GL_TEXTURE_2D, texture_nomes[31]);
        } else if(i==1) {
            glBindTexture(GL_TEXTURE_2D, texture_nomes[30]);
        } else if(i==0) {
            glBindTexture(GL_TEXTURE_2D, texture_nomes[28]);
        } else {
            glBindTexture(GL_TEXTURE_2D, texture_nomes[24]);
        }
        glPushMatrix();
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(&v[faces[i][0]][0]);

        glTexCoord2f(0.0, 1.0);
        glVertex3fv(&v[faces[i][1]][0]);

        glTexCoord2f(1.0, 1.0);
        glVertex3fv(&v[faces[i][2]][0]);

        glTexCoord2f(1.0, 0.0);
        glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();//---pode tirar
//-----------------------------Movimentacao calculo---------------------------------
    /*
    *Move marco
    */

    static float angle = 0;
    static float pos_x = 0;
    static float pos_z = 0;
    static float pos_y = 0;

    static int lastTime = 0;
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    float deltaT = (currentTime - lastTime)/1000.0;
    lastTime = currentTime;

    glLoadIdentity();

    angle += rot_rate*deltaT;

    pos_x += -2*trans_rate*sin(M_PI*angle/180);
    pos_z += 2*trans_rate*cos(M_PI*angle/180);

    pos_z += -2*transl_rate*sin(M_PI*angle/180);
    pos_x += 2*transl_rate*cos(M_PI*angle/180);

    pos_y += 2*ytrans_rate*sin(M_PI*angle/180);//sobe-desce
//-----------------------------movimentacao trans-rot----------------------------------

    bracotela();
    glRotatef(-angle, 0.0, -1.0, 0.0);
    glTranslatef(pos_x, pos_y, pos_z);
    glTranslatef(0.0,-3.0,0.0);


//-------------------------------------------------------------------------------------
    int i, j;

//---------------------------------Desenhando Nuvem-----------------------------

    glPushMatrix();
        glTranslatef(trans_x+25, 0, -40);
        desenhaNuvem();
    glPopMatrix();

     glPushMatrix();
        glTranslatef(trans_x+20, 0, -20);
        desenhaNuvem();

    glPopMatrix();

    glPushMatrix();
        glTranslatef(trans_x+30, 0, 10);
        desenhaNuvem();

    glPopMatrix();

//---------------------------------Ahs-----------------------------
     glPushMatrix();
      glRotatef(180,0.0,-1.0,0.0);
        glTranslatef(12, -0.2, 15);
        desenhaAhs();
    glPopMatrix();
//----------------Sol----------------------------
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture_nomes[19]);
        glTranslatef(trans_x_SolLua, trans_y, 0.0);
        desenhaSol();
         glClearColor(0.53, 0.81, 0.98, 0.0);
    glPopMatrix();

//---------------------------------Desenhando Miltank-----------------------------
     glPushMatrix();
        glTranslatef(-15, -0.2, -12);
        glRotatef(-45,0.0,-1.0,0.0);
        desenhaMiltank();
     glPopMatrix();

//---------------------------------Desenhando Pikachu-----------------------------
    glPushMatrix();
        glTranslatef(2, -0.2, -5);
        desenhaPikachu();
    glPopMatrix();


//---------------------------------Desenhando Arvore-----------------------------


    //Arvore 01
        glPushMatrix();
            glTranslatef(4, 1.0, -2);
            desenhaArvore();
        glPopMatrix();

        //Arvore 02
        glPushMatrix();
            glTranslatef(6, 1.0, -10);
            desenhaArvore();
        glPopMatrix();

        //Arvore 03
        glPushMatrix();
            glTranslatef(11, 1.0, 5);
            desenhaArvore();
        glPopMatrix();

        //Arvore 04
        glPushMatrix();
            glTranslatef(8, 1.0, 10);
            desenhaArvore();
        glPopMatrix();

        //Arvore 05
        glPushMatrix();
            glTranslatef(-22, 1.0, 10);
            desenhaArvore();
        glPopMatrix();

        //Arvore 06
        glPushMatrix();
            glTranslatef(-25, 1.0, -5);
            desenhaArvore();
        glPopMatrix();

        //Arvore 07
        glPushMatrix();
            glTranslatef(-22, 1.0, 5);
            desenhaArvore();
        glPopMatrix();

        //Arvore 08
        glPushMatrix();
            glTranslatef(-22, 1.0, 10);
            desenhaArvore();
        glPopMatrix();


     // arvore em cima
        glPushMatrix();
            glTranslatef(-22, 5.0, -10);
            desenhaArvore();
        glPopMatrix();

//---------------------------------Desenhando Montanha-----------------------------
    glPushMatrix();
       glTranslatef(-1, 0, 4);
       desenhaMontanha();
    glPopMatrix();
      glPushMatrix();
       glTranslatef(4, 0, 4);
      desenhaMontanha();
    glPopMatrix();

    glPushMatrix();
       glTranslatef(2, 2, 4);
       desenhaMontanha();
    glPopMatrix();

//---------------------------------Desenhando Terra-----------------------------
       desenhaTerra2();
       desenhaSoloIlha();
//---------------------------------Desenhando Ginasio -----------------------------
glPushMatrix();
        glRotatef(90,0.0,-1.0,0.0);
        glTranslatef(30, 4.2, 35);
        desenhaGinasio();
    glPopMatrix();
//-----------------------------------------------------
    glFlush();
    glutPostRedisplay();
}
//-------move marco------------------------
void keyboard(unsigned char key, int xx, int yy) {
    printf("Down: %d\n", key);
    switch(key) {

    case 'a':
    case 'A':
        rot_rate = -25*move;
        break;

    case 'd':
    case 'D':
        rot_rate = 25*move;
        break;

    case 'w':
    case 'W':
        trans_rate = move;
        break;

    case 's':
    case 'S':
        trans_rate = -move;
        break;

    case 'r':
    case 'R':
        ytrans_rate = move;

        break;

    case 't':
    case 'T':
        ytrans_rate = -move;
        break;

    case 'q':
    case 'Q':
        transl_rate = move;
        break;

    case 'e':
    case 'E':
        transl_rate = -move;
        break;

    case 27:
        exit(0);
        break;
    }
}
void keyboardup(unsigned char key, int x, int y) {
    printf("Up %d\n", key);
    switch(key) {
    case 'p':
    case 'P':
         poker=1;
    break;

    case 'o':
    case 'O':
         poker=0;
    break;

    case 'a':
    case 'd':
    case 'A':
    case 'D':


        rot_rate = 0;
        break;

    case 'w':
    case 'W':
    case 's':
    case 'S':


        trans_rate = 0;
        break;

    case 'r':
    case 'R':
    case 't':
    case 'T':

        ytrans_rate = 0;
        break;

    case 'q':
    case 'Q':
    case 'e':
    case 'E':
        transl_rate = 0;
        break;

    case 27:
        exit(0);
        break;
    }
}
//-----------------------------------------------
