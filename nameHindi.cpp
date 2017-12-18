#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

int main()
{
    initwindow(1000, 900);
    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;

    int mb[4][4] = {    {-1, 3, -3, 1},
                        {3, -6, 3, 0},
                        {-3, 3, 0, 0},
                        {1, 0, 0, 0}};

    int crv = 14;

    int points[4][2*crv] = {    {-200,70,   -110,70,    -200,70,  -110,45, -110,0, -110,0, 150,70,   150,70, 70,70, 70,45, 70,-50, 17,0, -40,0,    -240,70},
                                {-200,70,   -110,65,  -255,150,   -145,40, -90,0,  -250,0, 150,70,   55,150, 70,65, 0,45,  70,-55, 17,0, -40,-30,   -240,70},
                                {-200,-70,  -110,60, -200,140,   -175,10,  -90,-35,-100,-96,150,-70,  -20,140, 70,60, 0,-50, 80,-80,-40,0, -30,-30,   200,70},
                                {-200,-70,  -110,45,   -110,70,   -110,10, -110,-50,-110,-90,150,-70, 70,70,  70,45,  70,-50,80,-75,-40,0, -20,0,      200,70}  };

    for (int col = 0; col < 2 * crv; col += 2) {
        int prod[4][2*crv];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2 * crv; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += mb[i][k] * points[k][j];
                }
                prod[i][j] = sum;
            }
        }

        for (float t = 0; t <= 1; t += 0.001) {
            float t3 = t*t*t, t2 = t*t, x, y;
            x = t3 * prod[0][col] + t2 * prod[1][col] + t * prod[2][col] + prod[3][col];
            y = t3 * prod[0][col+1] + t2 * prod[1][col+1] + t * prod[2][col+1] + prod[3][col+1];
            putpixel(xc + x, yc - y, WHITE);
        }
    }

    int points_double[4][2*crv] = {{-210,70, -120,65, -210,70,  -120,50, -110,0, -110,0, 160,70,   150,70, 80,70, 70,45, 70,-50, 17,10, -40,0,    -240,80},
                                {-210,70,   -120,60,  -265,160, -180,50, -90,0,  -250,0, 160,70,   55,150, 80,65, 0,45,  70,-55, 17,10, -40,-30,   -240,80},
                                {-210,-70,  -120,60, -210,130,  -180,-5,  -90,-35,-100,-96,160,-70,  -20,140, 80,60, 0,-50, 80,-80,-40,10, -30,-30,   200,80},
                                {-210,-70,  -120,45, -120,65,   -120,0, -110,-50,-110,-90,160,-70, 70,70,  80,45,  70,-50,80,-75,-40,10, -20,0,      200,80}  };

    for (int col = 0; col < 2 * crv; col += 2) {
        int prod[4][2*crv];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2 * crv; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += mb[i][k] * points_double[k][j];
                }
                prod[i][j] = sum;
            }
        }

        for (float t = 0; t <= 1; t += 0.001) {
            float t3 = t*t*t, t2 = t*t, x, y;
            x = t3 * prod[0][col] + t2 * prod[1][col] + t * prod[2][col] + prod[3][col];
            y = t3 * prod[0][col+1] + t2 * prod[1][col+1] + t * prod[2][col+1] + prod[3][col+1];
            putpixel(xc + x, yc - y, WHITE);
        }
    }


    getch();
    return 0;
}