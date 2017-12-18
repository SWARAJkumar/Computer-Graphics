#include <bits/stdc++.h>
#include <graphics.h>
#define rad(a)      a * 3.1416 / 180

using namespace std;

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2;

    int letterS[4][24] = {  {0, 40, 40, 10, 10, 40, 40, 0, 0, 30, 30, 0, 0, 40, 40, 10, 10, 40, 40, 0, 0, 30, 30, 0},
                            {0, 0, 40, 40, 60, 60, 70, 70, 30, 30, 10, 10, 0, 0, 40, 40, 60, 60, 70, 70, 30, 30, 10, 10},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}    };

    int letterI[4][8] = {  {0, 10, 10, 0, 0, 10, 10, 0},
                            {0, 0, 70, 70, 0, 0, 70, 70},
                            {0, 0, 0, 0, 10, 10, 10, 10},
                            {1, 1, 1, 1, 1, 1, 1, 1}    };

    int letterN[4][20] = {  {0, 10, 10, 25, 40, 40, 30, 30, 15, 0, 0, 10, 10, 25, 40, 40, 30, 30, 15, 0},
                            {0, 0, 60, 0, 0, 70, 70, 10, 70, 70, 0, 0, 60, 0, 0, 70, 70, 10, 70, 70},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}    };

    int letterH[4][24] = {  {0, 10, 10, 30, 30, 40, 40, 30, 30, 10, 10, 0, 0, 10, 10, 30, 30, 40, 40, 30, 30, 10, 10, 0},
                            {0, 0, 30, 30, 0, 0, 70, 70, 40, 40, 70, 70, 0, 0, 30, 30, 0, 0, 70, 70, 40, 40, 70, 70},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}    };

    int letterAout[4][16] = {   {0, 10, 10, 30, 30, 40, 40, 0, 0, 10, 10, 30, 30, 40, 40, 0},
                                {0, 0, 30, 30, 0, 0, 70, 70, 0, 0, 30, 30, 0, 0, 70, 70},
                                {0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}    };

    int letterAin[4][8] = { {10, 30, 30, 10, 10, 30, 30, 10},
                            {40, 40, 60, 60, 40, 40, 60, 60},
                            {0, 0, 0, 0, 10, 10, 10, 10},
                            {1, 1, 1, 1, 1, 1, 1, 1}    };


    int inc = 0, page = 0;
    while (1){
        double a = 45, b = 35.26;
        float rot[4][4] = { {cos(rad(b)), sin(rad(a+inc))*sin(rad(b)), -cos(rad(a+inc))*sin(rad(b)), 0},
                            {0, cos(rad(a+inc)), sin(rad(a+inc)), -35*cos(rad(a+inc))},
                            {sin(rad(b)), -sin(rad(a+inc))*cos(rad(b)), cos(rad(a+inc))*cos(rad(b)), 0},
                            {0, 0, 0, 1}   };


//  drawing letter S
        float prodS[4][24];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 24; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 2 * rot[i][k] * letterS[k][j];
                }
                prodS[i][j] = sum;
            }
        }
        for (int i = 0; i < 12; ++i) {
            line(xc - 240 + prodS[0][i], yc - prodS[1][i], xc - 240 + prodS[0][(i+1)%12], yc - prodS[1][(i+1)%12]);
            line(xc - 240 + prodS[0][i], yc - prodS[1][i], xc - 240 + prodS[0][i+12], yc - prodS[1][i+12]);
            line(xc - 240 + prodS[0][i+12], yc - prodS[1][i+12], xc - 240 + prodS[0][(i+1)%12+12], yc - prodS[1][(i+1)%12+12]);
        }


//  drawing letter I
        float prodI[4][8];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 2 * rot[i][k] * letterI[k][j];
                }
                prodI[i][j] = sum;
            }
        }
        for (int i = 0; i < 4; ++i) {
            line(xc - 130 + prodI[0][i], yc - prodI[1][i], xc - 130 + prodI[0][(i+1)%4], yc - prodI[1][(i+1)%4]);
            line(xc - 130 + prodI[0][i], yc - prodI[1][i], xc - 130 + prodI[0][i+4], yc - prodI[1][i+4]);
            line(xc - 130 + prodI[0][i+4], yc - prodI[1][i+4], xc - 130 + prodI[0][(i+1)%4+4], yc - prodI[1][(i+1)%4+4]);
        }


        float prodN[4][20];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 20; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 2 * rot[i][k] * letterN[k][j];
                }
                prodN[i][j] = sum;
            }
        }
        for (int i = 0; i < 10; ++i) {
            line(xc - 80 + prodN[0][i], yc - prodN[1][i], xc - 80 + prodN[0][(i+1)%10], yc - prodN[1][(i+1)%10]);
            line(xc - 80 + prodN[0][i], yc - prodN[1][i], xc - 80 + prodN[0][i+10], yc - prodN[1][i+10]);
            line(xc - 80 + prodN[0][i+10], yc - prodN[1][i+10], xc - 80 + prodN[0][(i+1)%10+10], yc - prodN[1][(i+1)%10+10]);
        }


        float prodH[4][24];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 24; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 2 * rot[i][k] * letterH[k][j];
                }
                prodH[i][j] = sum;
            }
        }
        for (int i = 0; i < 12; ++i) {
            line(xc + 30 + prodH[0][i], yc - prodH[1][i], xc + 30 + prodH[0][(i+1)%12], yc - prodH[1][(i+1)%12]);
            line(xc + 30 + prodH[0][i], yc - prodH[1][i], xc + 30 + prodH[0][i+12], yc - prodH[1][i+12]);
            line(xc + 30 + prodH[0][i+12], yc - prodH[1][i+12], xc + 30 + prodH[0][(i+1)%12+12], yc - prodH[1][(i+1)%12+12]);
        }

//  drawing letter A
        float prodAout[4][16];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 16; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 2 * rot[i][k] * letterAout[k][j];
                }
                prodAout[i][j] = sum;
            }
        }
        for (int i = 0; i < 8; ++i) {
            line(xc + 140 + prodAout[0][i], yc - prodAout[1][i], xc + 140 + prodAout[0][(i+1)%8], yc - prodAout[1][(i+1)%8]);
            line(xc + 140 + prodAout[0][i], yc - prodAout[1][i], xc + 140 + prodAout[0][i+8], yc - prodAout[1][i+8]);
            line(xc + 140 + prodAout[0][i+8], yc - prodAout[1][i+8], xc + 140 + prodAout[0][(i+1)%8+8], yc - prodAout[1][(i+1)%8+8]);
        }

        float prodAin[4][8];        //A's inside line
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 2 * rot[i][k] * letterAin[k][j];
                }
                prodAin[i][j] = sum;
            }
        }
        for (int i = 0; i < 4; ++i) {
            line(xc + 140 + prodAin[0][i], yc - prodAin[1][i], xc + 140 + prodAin[0][(i+1)%4], yc - prodAin[1][(i+1)%4]);
            line(xc + 140 + prodAin[0][i], yc - prodAin[1][i], xc + 140 + prodAin[0][i+4], yc - prodAin[1][i+4]);
            line(xc + 140 + prodAin[0][i+4], yc - prodAin[1][i+4], xc + 140 + prodAin[0][(i+1)%4+4], yc - prodAin[1][(i+1)%4+4]);
        }

        setactivepage(page), setvisualpage(1-page);
        inc++;     delay(10);     page = 1 - page;
        cleardevice();
    }

    getch();
    return 0;
}
