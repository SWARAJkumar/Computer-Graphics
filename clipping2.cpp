#include <bits/stdc++.h>
#include <graphics.h>

#define xx first
#define yy second
#define pb push_back

using namespace std;

vector<pair<int, int> > v,edges,normal;
vector<pair<double, double> > intsc;
vector<int> numr,demr;
vector<double> t;

pair<int, int> p1={20, 60}, p2={80, 0};

int main()
{
    //Enter Vertices.
    v.pb({35,100});
    v.pb({30,60});
    v.pb({80,70});
    v.pb({30,50});
    v.pb({100,40});
    v.pb({10,10});
    int count=0;
    initwindow(1200, 700, "");

while(1){
   cleardevice();
   setcolor(BLUE);
   for(int i=0; i<6; i++)
    {
        line( v[i].xx, v[i].yy, v[(i+1)%6].xx, v[(i+1)%6].yy );
    }
    //Calculate Edges.
    for(int i=0; i<6; i++)
        edges.pb( { v[(i+1)%6].xx - v[i].xx , v[(i+1)%6].yy - v[i].yy } );

    for(int i=0; i<6; i++)
        normal.pb( { -1*edges[i].yy, edges[i].xx } );

    for(int i=0; i<6; i++)
        numr.pb( normal[i].xx * ( p1.xx-count - v[i].xx) + normal[i].yy * (p1.yy - v[i].yy) );

    for(int i=0; i<6; i++)
        demr.pb( -1*(normal[i].xx * ( p2.xx - p1.xx-count) + normal[i].yy * (p2.yy - p1.yy) ));

    for(int i=0; i<6; i++)
        t.pb(double( double(numr[i])/double(demr[i]) ) );




    //Output Table.
    cout<<"   Edges\tNormal\t\tNume\tDenom\t t\n";

    for(int i=0; i<6; i++)
    {
        cout<<edges[i].xx<<"\t"<<edges[i].yy<<"\t"<<normal[i].xx<<"\t"<<normal[i].yy<<
        "\t"<<numr[i]<<"\t"<<demr[i]<<"\t"<<t[i]<<endl;
    }


    sort(t.begin(), t.end());

    //Clipping. Find Intersections.
    for(int i=0; i<6; i++)
    {
        if(t[i]<=1 && t[i]>=0)
        {
            int xi=p1.xx-count + ((p2.xx-p1.xx-count)*t[i]);
            int yi=p1.yy + ((p2.yy-p1.yy)*t[i]);
            intsc.pb({xi,yi});
        }
    }



    //Output Graph.

    int xc=getmaxx()/2, yc=getmaxy()/2;

    setcolor(RED);
    //Output Polygon.

    //Output Line.
    line(p1.xx-count, p1.yy, p2.xx, p2.yy);

    //Output Clipped Lines.
    setcolor(YELLOW);
    cout<<endl<<intsc.size()<<endl;
    for(int i=1; i<intsc.size(); i+=2)
    {
        line(intsc[i-1].xx, intsc[i-1].yy, intsc[i].xx, intsc[i].yy);
    }
    count+=2;
    delay(1000);
}//end of while

    getch();

    return 0;
}
