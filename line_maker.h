#include<graphics.h>
#include<math.h>


// CASE 1 m<1

void caseone(float m,int x1, int y1, int x2, int y2){

float x= (float)x1,y= (float)y1;

while(x<=(float)x2){

x+=1.0;

y+=m;

putpixel(round(x)+50,round(y)+50,5);

delay(30);
}

}

// CASE 2 m=1

void casetwo(float invm,int x1, int y1, int x2, int y2){

float x= (float)x1,y= (float)y1;

while(y<=(float)y2){

x+=1.0;
y+=1.0;
putpixel(round(x)+50,round(y)+50,5);

delay(30);
}

}

// CASE 3 m>1

void casethree(float invm,int x1, int y1, int x2, int y2){

float x= (float)x1,y= (float)y1;

while(y<=(float)y2){

x+=invm;
y+=1.0;
putpixel(round(x)+50,round(y)+50,5);

delay(30);
}

}



// Main

void plot(int x1,int y1,int x2,int y2){

//cout<<"First Cordinates \n";
//cin>>x1>>y1;
//cout<<"Second Cordinates \n";
//cin>>x2>>y2;

float dx=x2-x1, dy=y2-y1;

float m=dy/dx;


if(m<=1.0){
//cout<<"m : "<<m<<endl;
caseone(m,x1,y1,x2,y2);
}

else if(m==1.0)
{
casetwo(m,x1,y1,x2,y2);
}

else{

float invm = 1/m;

//cout<<"m : "<<m<<endl;

casethree(invm,x1,y1,x2,y2);
}

}


