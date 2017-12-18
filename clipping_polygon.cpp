#include <bits/stdc++.h>x
#include <graphics.h>
using namespace std;

#define MAX1 3
#define MAX2 5
#define xx first
#define yy second

pair<int,int> subject[MAX1]= {{60,60},{100,20},{10,10}};
pair<int, int> clip[MAX2]={{20,100},{30,60},{60,30},{40,60},{100,40}};

void clipper(pair<int,int>, pair<int,int>){
    vector<pair<int, int> > v,edges,normal;
    vector<pair<double, double> > intsc;
    vector<int> numr,demr;
    vector<double> t;
    for(int i=0;i<MAX1;i++){
        v.push_back(subject[i]);
    }

   for(int i=0; i<MAX1; i++)
        edges.pb( { v[(i+1)%MAX1].xx - v[i].xx , v[(i+1)%MAX1].yy - v[i].yy } );

    for(int i=0; i<MAX1; i++)
        normal.pb( { -1*edges[i].yy, edges[i].xx } );

    for(int i=0; i<MAX1; i++)
        numr.pb( normal[i].xx * ( p1.xx-count - v[i].xx) + normal[i].yy * (p1.yy - v[i].yy) );

    for(int i=0; i<MAX1; i++)
        demr.pb( -1*(normal[i].xx * ( p2.xx - p1.xx-count) + normal[i].yy * (p2.yy - p1.yy) ));

    for(int i=0; i<6; i++)
        t.pb(double( double(numr[i])/double(demr[i]) ) );




    //Output Table.
    cout<<"   Edges\tNormal\t\tNume\tDenom\t t\n";

    for(int i=0; i<MAX1; i++)
    {
        cout<<edges[i].xx<<"\t"<<edges[i].yy<<"\t"<<normal[i].xx<<"\t"<<normal[i].yy<<
        "\t"<<numr[i]<<"\t"<<demr[i]<<"\t"<<t[i]<<endl;
    }


    sort(t.begin(), t.end());

    //Clipping. Find Intersections.
    for(int i=0; i<MAX1; i++)
    {
        if(t[i]<=1 && t[i]>=0)
        {
            int xi=p1.xx + ((p2.xx-p1.xx)*t[i]);
            int yi=p1.yy + ((p2.yy-p1.yy)*t[i]);
            intsc.pb({xi,yi});
        }
    }



    //Output Graph.
/*
    int xc=getmaxx()/2, yc=getmaxy()/2;

    setcolor(RED);
    //Output Polygon.

    //Output Line.
    line(p1.xx, p1.yy, p2.xx, p2.yy);

    //Output Clipped Lines.
    setcolor(YELLOW);

    cout<<endl<<intsc.size()<<endl;
    for(int i=1; i<intsc.size(); i+=2)
    {
        line(intsc[i-1].xx, intsc[i-1].yy, intsc[i].xx, intsc[i].yy);
    }
    */
}
int main(){
    initwindow(1200,700);
    int xc = getmaxx()/2;
    int yx = getmaxy()/2;

    setcolor(BLUE);
   for(int i=0; i<MAX1; i++)
    {
        line( subject[i].xx, subject[i].yy, subject[(i+1)%MAX1].xx, subject[(i+1)%MAX1].yy );
    }
    setcolor(RED);
    for(int i=0; i<MAX2; i++)
    {
        line( clip[i].xx, clip[i].yy, clip[(i+1)%MAX2].xx,clip[(i+1)%MAX2].yy );
    }
    for(int i=0; i<MAX2;i++){
        clipper(clip[i],clip,)
    }

    getch();
}
