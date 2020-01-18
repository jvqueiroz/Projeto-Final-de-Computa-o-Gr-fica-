#include "draws.h"

GLuint texture_nomes [80];
int i;
float y=-3.5;

GLint faces[6][4] = {
    {0,1,2,3}, {3,2,6,7}, {7,6,5,4},
    {4,5,1,0}, {5,6,2,1}, {7,4,0,3}
};

GLfloat v[8][3];

int VariaDiaNoite=0;
float trans_x;
float trans_y;
float trans_x_SolLua;
float posx = 0.0, posz = -5.0, posy= 0.0, angle = 0.0, bottom = 0.0;

void drawCube(){
    int i;
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


void drawCube1(){

    int i;

    for(i = 0; i < 6; i++){
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[faces[i][0]][0]);

            glTexCoord2f(0.0, 3.0);
            glVertex3fv(&v[faces[i][1]][0]);

            glTexCoord2f(3.0, 3.0);
            glVertex3fv(&v[faces[i][2]][0]);

            glTexCoord2f(3.0, 0.0);
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
                    glBindTexture(GL_TEXTURE_2D, texture_nomes[5]);
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
                    glBindTexture(GL_TEXTURE_2D, texture_nomes[5]);


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

    //Pedras
    glPushMatrix();
        glScalef(1, 1, 1);
        glTranslatef(-21, 2,-32);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[8]);
        drawCube();

        glTranslatef(2, 0,0);
        drawCube();

        glTranslatef(2, 0,4);
        drawCube();
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

static void desenhaPoco(){
    glPushMatrix(); //Pedra
        glScalef(3, 1, 3);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[9]);
        glTranslatef(-8, 2.0, -3);
        drawCube();
    glPopMatrix();


    glPushMatrix(); //PedraCima
        glScalef(3, 1, 3);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[9]);
        glTranslatef(-8, 8.0, -3);
        drawCube();
    glPopMatrix();

    //Pilares

     glPushMatrix();
        glScalef(0.3, 3, 0.3);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[4]);
        glTranslatef(-88, 2.0, -22);
        drawCube();
    glPopMatrix();

     glPushMatrix();
        glScalef(0.3, 3, 0.3);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[4]);
        glTranslatef(-88, 2.0, -38);
        drawCube();
    glPopMatrix();


     glPushMatrix();
        glScalef(0.3, 3, 0.3);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[4]);
        glTranslatef(-72, 2.0, -22);
        drawCube();
    glPopMatrix();

     glPushMatrix();
        glScalef(0.3, 3, 0.3);
        glBindTexture(GL_TEXTURE_2D, texture_nomes[4]);
        glTranslatef(-72, 2.0, -38);
        drawCube();
    glPopMatrix();
}

//Chao1
static void desenhaAgua (){
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

//Casa
static void desenhaCasa(){

    glPushMatrix(); //
        glBindTexture(GL_TEXTURE_2D, texture_nomes[4]);
        glTranslatef(-14, 4, -20);
        glScalef(3, 3, 4);
        drawCube1();



    glPopMatrix();

    //porta
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture_nomes[3]);
        glTranslatef(-14, 2.4, -15.9);
        glScalef(0.8, 2.1, 0);
        drawCube();

    glPopMatrix();

    //Teto


    glPushMatrix(); //
        glBindTexture(GL_TEXTURE_2D, texture_nomes[0]);
        glTranslatef(-14, 6.5, -20);
        glScalef(4, 0.9, 5);
        drawCube1();

    glPopMatrix();
}

//Ahs
static void desenhaZombie(){
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

//Miltank
static void desenhaOvelha(){

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

//Lua
static void desenhaLua(){
       glPushMatrix();
            glTranslatef(-40, 10, -75);
            glScalef(3.0, 3.0, 1.0);
            drawCube();
         glPopMatrix();
}
//Nuvem
 static void desenhaNuvem(){
    int i , j;
        glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);
        glTranslatef(-70, 20, 0);
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
static void desenhaLuaOuSol(){
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
      glTranslatef(-57.0, 6.0, -21.0);
      glScalef(1.0, 11.5, 4.0);
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
}

//**************************************************************************************************************

void display(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-angle, 0.0, 2.0, 0.0);
    glTranslatef(posx, posy, posz);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTranslatef(0.0,-3.0,0.0);

//Madeira = 0  |||  Terra= 1 |||  Folhas= 2  |||  Porta= 3  |||  Madeira Refinada =4   |||  Areia = 5
//Capim= 6     |||  Agua= 7  |||  Pedra= 8   |||  Pedregulho  = 9

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

//---------------------------------efeito noite - dia-----------------------------

   // if(VariaDiaNoite==0){
            /*
    // zombie 1
        glPushMatrix();

        glTranslatef(-30, -0.2, -10);
        glRotatef(-130.0, 0.0, 1.0, 0.0);
        desenhaZombie();
    glPopMatrix();*/

    //zombie 2
     glPushMatrix();

        glTranslatef(-50, -0.2, -25);
        glRotatef(-90.0, 0.0, 1.0, 0.0);
        desenhaZombie();
    glPopMatrix();
//----------------
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture_nomes[19]);
        glTranslatef(trans_x_SolLua, trans_y, 0.0);
        desenhaLuaOuSol();
         glClearColor(0.53, 0.81, 0.98, 0.0);
    glPopMatrix();

    //}
    /*else{
        glPushMatrix();
            glTranslatef(trans_x_SolLua, trans_y, 0.0);
            glBindTexture(GL_TEXTURE_2D, texture_nomes[19]);
            desenhaLuaOuSol();

        glPopMatrix();

    }*/

//---------------------------------Desenhando Ovelha-----------------------------
    glPushMatrix();
        glTranslatef(-11, -0.2, -14);
        desenhaOvelha();
    glPopMatrix();
//---------------------------------Desenhando Arvore-----------------------------

    float z= -2;

    for(i=0; i<3; i++){
        glPushMatrix();
            glTranslatef(i+1, 1.0, z-1);
            desenhaArvore();
        glPopMatrix();
            z*= -2.5;
    }
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


//---------------------------------Desenhando agua-----------------------------
    desenhaAgua ();


//---------------------------------Desenhando Ilha - Solo-----------------------------
    desenhaSoloIlha();


//---------------------------------Desenhando Casa-----------------------------
    glPushMatrix();
        glTranslatef(3, 0, 0);
        desenhaCasa();
    glPopMatrix();

//---------------------------------Desenhando Poço -----------------------------
    //desenhaPoco();

      desenhaGinasio();



//----------------------------------------------------------------------
    glFlush();

}
