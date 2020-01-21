#include "texture.h"

extern GLuint texture_nomes [80];
extern float posx, posz, posy, angle, bottom;

void makeTexture(void){
    GLubyte texture[16][16][3];
    GLubyte *loc;
    int s,t;

    /*Setup RGB image of the texture. */
    loc = (GLubyte*) texture;
        for(t=0; t<16; t++){
            for(s=0; s< 16; s++){

                    /* Light gray */
                    loc[0] = 0xaa;
                    loc[1] = 0xaa;
                    loc[2]= 0xaa;

                loc += 3;
            }
        }
        int larg, alt;

    unsigned char *data = load_bmp("madeira.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);

    //-----------------------------------------------------------

    unsigned char *chao_terra1 = load_bmp("chaoTerra.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, chao_terra1);
    free(chao_terra1);


    unsigned char *folhas = load_bmp("folha.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, folhas);
    free(folhas);


    unsigned char *porta = load_bmp("porta.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[3]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, porta);
    free(porta);


    unsigned char *madeira_refinada = load_bmp("madeiraRefinada.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[4]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, madeira_refinada);
    free(madeira_refinada);


    unsigned char *chao_areia = load_bmp("chaoAreia.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[5]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, chao_areia);
    free(chao_areia);


    unsigned char *capim = load_bmp("chaoCapim.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[6]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, capim);
    free(capim);


    unsigned char *chao_terra2 = load_bmp("ChaoGrama.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[7]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, chao_terra2);
    free(chao_terra2);


    unsigned char *pedra = load_bmp("pedra.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[8]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, pedra);
    free(pedra);


    unsigned char *pedregulho = load_bmp("pedregulho.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[9]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, pedregulho);
    free(pedregulho);


    unsigned char *MiltankCabecaFrente = load_bmp("MiltankCabeçaFrente.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[10]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCabecaFrente);
    free(MiltankCabecaFrente);


    unsigned char *zombieRosto = load_bmp("Cabeça.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[13]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, zombieRosto);
    free(zombieRosto );


    unsigned char *zombieCor= load_bmp("Braço.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[14]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, zombieCor);
    free(zombieCor);


    unsigned char *zombieCamisa= load_bmp("Corpo.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[15]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, zombieCamisa);
    free(zombieCamisa);


    unsigned char *zombieCalca= load_bmp("Pernas.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[16]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, zombieCalca);
    free(zombieCalca);


    unsigned char *nuvem= load_bmp("nuvem.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[17]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, nuvem);
    free(nuvem);


    unsigned char *lua= load_bmp("lua.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[18]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, lua);
    free(lua);


    unsigned char *sol= load_bmp("sol.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[19]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, sol);
    free(sol);

    unsigned char *LadoAhs= load_bmp("Lado.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[20]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, LadoAhs);
    free(LadoAhs);


    unsigned char *CabecaCostaAhs= load_bmp("CabeçaCosta.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[21]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, CabecaCostaAhs);
    free(CabecaCostaAhs);

     unsigned char *CabecaCimaAhs= load_bmp("CabeçaCima.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[22]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, CabecaCimaAhs);
    free(CabecaCimaAhs);

    unsigned char *CabecaLado2Ahs= load_bmp("Lado2.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[23]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, CabecaLado2Ahs);
    free(CabecaLado2Ahs);


    unsigned char *CabecaBaixoAhs= load_bmp("CabeçaBaixo.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[24]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, CabecaBaixoAhs);
    free(CabecaBaixoAhs);


    unsigned char *CorpoLado2= load_bmp("CorpoLado2.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[25]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, CorpoLado2);
    free(CorpoLado2);


    unsigned char *CorpoLado= load_bmp("CorpoLado.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[26]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, CorpoLado);
    free(CorpoLado);


    unsigned char *CorpoCosta= load_bmp("CorpoCosta.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[27]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, CorpoCosta);
    free(CorpoCosta);



    unsigned char *BracoLado= load_bmp("BraçoLado.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[28]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, BracoLado);
    free(BracoLado);


    unsigned char *BracoLado2= load_bmp("BraçoLado2.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[29]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, BracoLado2);
    free(BracoLado2);



    unsigned char *BracoCima= load_bmp("BraçoCima.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[30]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, BracoCima);
    free(BracoCima);



    unsigned char *BracoCostas= load_bmp("BraçoCostas.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[31]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, BracoCostas);
    free(BracoCostas);



    unsigned char *PernasCostas= load_bmp("PernasCosta.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[32]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, PernasCostas);
    free(PernasCostas);



    unsigned char *PernasLado= load_bmp("PernasLado.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[33]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, PernasLado);
    free(PernasLado);



     unsigned char *PernasLado2= load_bmp("PernasLado2.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[34]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, PernasLado2);
    free(PernasLado2);



    unsigned char *MiltankCabecaCima = load_bmp("MiltankCabeçaCima.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[35]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCabecaCima);
    free(MiltankCabecaCima);


    unsigned char *MiltankCabecaLado = load_bmp("MiltankCabeçaLado.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[36]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCabecaLado);
    free(MiltankCabecaLado);


    unsigned char *MiltankCabecaLado2 = load_bmp("MiltankCabeçaLado2.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[37]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCabecaLado2);
    free(MiltankCabecaLado2);


    unsigned char *MiltankCabecaTras = load_bmp("MiltankCabeçaTras.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[38]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCabecaTras);
    free(MiltankCabecaTras);


    unsigned char *MiltankCorpoFrente = load_bmp("MiltankCorpoFrente.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[39]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCorpoFrente);
    free(MiltankCorpoFrente);


    unsigned char *MiltankCorpoLado = load_bmp("MiltankCorpoLado.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[40]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCorpoLado);
    free(MiltankCorpoLado);


    unsigned char *MiltankCorpoLado2 = load_bmp("MiltankCorpoLado2.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[41]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCorpoLado2);
    free(MiltankCorpoLado2);



    unsigned char *MiltankCorpoCosta = load_bmp("MiltankCorpoCosta.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[42]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCorpoCosta);
    free(MiltankCorpoCosta);


    unsigned char *MiltankCorpoCima = load_bmp("MiltankCorpoCima.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[43]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankCorpoCima);
    free(MiltankCorpoCima);


    unsigned char *MiltankPataFrente = load_bmp("MiltankPataFrente.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[44]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankPataFrente);
    free(MiltankPataFrente);



    unsigned char *MiltankPataCosta = load_bmp("MiltankPataCosta.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[45]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankPataCosta);
    free(MiltankPataCosta);



    unsigned char *MiltankPataLado = load_bmp("MiltankPataLado.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[46]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankPataLado);
    free(MiltankPataLado);



    unsigned char *MiltankPataLado2 = load_bmp("MiltankPataLado2.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[47]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, MiltankPataLado2);
    free(MiltankPataLado2);


    unsigned char *GinasioParede = load_bmp("GinasioParede.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[48]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, GinasioParede);
    free(GinasioParede);


    unsigned char *GinasioTelha = load_bmp("GinasioTelha.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[49]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, GinasioTelha);
    free(GinasioTelha);



    unsigned char *GinasioDetalhesAzuis = load_bmp("GinasioDetalhesAzuis.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[50]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, GinasioDetalhesAzuis);
    free(GinasioDetalhesAzuis);



    unsigned char *PikachuCabecaFrente = load_bmp("PikachuCabeçaFrente.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[51]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, PikachuCabecaFrente);
    free(PikachuCabecaFrente);


    unsigned char *PikachuCabecaLados = load_bmp("PikachuCabeçaLados.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[52]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, PikachuCabecaLados);
    free(PikachuCabecaLados);


    unsigned char *PikachuCabecaOrelhaFrente = load_bmp("PikachuCabeçaOrelhaFrente.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[53]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, PikachuCabecaOrelhaFrente);
    free(PikachuCabecaOrelhaFrente);



    unsigned char *PikachuCabecaCima= load_bmp("PikachuCabeçaCima.bmp", &larg, &alt);

    glBindTexture(GL_TEXTURE_2D, texture_nomes[54]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, larg, alt, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, PikachuCabecaCima);
    free(PikachuCabecaCima);



}//*****************************************
