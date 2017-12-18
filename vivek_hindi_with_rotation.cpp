#include <iostream>
#include <graphics.h>
#include <math.h>
#define rad(a)      3.14 * a / 180

using namespace std;

int main()
{
    initwindow(1200, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2;

    int crv = 8;
    //pointx matrix in a given row is written as:
    //x and y of 1st curve and then the next curve and column contains P1, P2, P3, P4 points

    int points[4][4*crv] = {    {-200,-150,-150,-200,  -200,-150,-150,-200,  -200,-210,-150,-150,  -120,-120,-70,-70,   -120,-120,-70,-70,   -40,-60,-60,-40, -40,-20,-30,-40, -40,-60,-60,-10},
                                {70,70,0,0,         0,0,-70,-60,       -60,-20,-120,-120,         0,-50,-50,0,        0,0,70,70,            55,55,70,70,     70,70,60,55,     55,0,0,-70},
                                {0,0,0,0,               0,0,0,0,             0,0,0,0,               0,0,0,0,              0,0,0,0,          0,0,0,0,          0,0,0,0,        0,0,0,0   },
                                {1,1,1,1,               1,1,1,1,             1,1,1,1,               1,1,1,1,              1,1,1,1,           1,1,1,1,          1,1,1,1,        1,1,1,1  }  };

   //circle drawn using 2 curves
    int page = 0;
//    int ang = 0;
    for (int ang = 0; !kbhit(); ++ang) {
        setvisualpage(1 - page),    setactivepage(page);
        cleardevice();
//        delay(10);

        //rotation matrix about y-axis
        float roty[4][4] = {    {cos(rad(ang)), 0, sin(rad(ang)), 0},
                                {0, 1, 0, 0},
                                {-sin(rad(ang)), 0, cos(rad(ang)), 0},
                                {0, 0, 0, 1}    };

        float rotx[4][4] = {    {1, 0, 0, 0},
                                {0, cos(rad(ang)), -sin(rad(ang)), 0},
                                {0, sin(rad(ang)), cos(rad(ang)), 0},
                                {0, 0, 0, 1}    };

        float rotz[4][4] = {    {cos(rad(ang)), -sin(rad(ang)), 0, 0},
                                {sin(rad(ang)), cos(rad(ang)), 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}    };

        float pts[4][4*crv];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 * crv; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += rotx[i][k] * points[k][j];
                }
                pts[i][j] = sum;
            }
        }

        for (int col = 0; col < 4 * crv; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * pts[0][col] + 3 * pow(1-t, 2) * t * pts[0][col+1] + 3 * (1-t) * t * t * pts[0][col+2] + pow(t, 3) * pts[0][col+3];
                y = pow(1-t, 3) * pts[1][col] + 3 * pow(1-t, 2) * t * pts[1][col+1] + 3 * (1-t) * t * t * pts[1][col+2] + pow(t, 3) * pts[1][col+3];
                putpixel(xc + x, yc - y, WHITE);
            }
        }
    }

    getch();
    return 0;
}
