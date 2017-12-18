#include<iostream>
#include"line_maker.h"

using  namespace std;

void frame(){
    plot(0,0,400,100);
    plot(0,0,10,50);
    plot(10,50,410,150);
    plot(400,100,410,150);
}
void support(){

    plot(100,200,200,100);
    plot(210,100,310,200);
    plot(100,200,310,201);
}

int main (){
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    frame();
    support();
    getch();
    closegraph();
    return 0;
}


