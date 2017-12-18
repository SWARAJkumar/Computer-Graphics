#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long int
#define mod 1000000007
#include<graphics.h>
using namespace std;
int main()
{    int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
     vector<pair<int,int> > vec;
	 vector<pair<int,int> > normal;
	 vector<pair<int,int> > edges;
     vector<int> num;
	 vector<int> denom;
	  vector<double> t ;
      pair<int,int> p1,p2;
      int i;
      vec.pb(mp(35,100));
      vec.pb(mp(30,60));
      vec.pb(mp(80,70));
      vec.pb(mp(30,50));
      vec.pb(mp(100,40));
      vec.pb(mp(10,10));
      line(35,100,30,60);
      line(30,60,80,70);
      line(80,70,30,50);
      line(30,50,100,40);
      line(100,40,10,10);
      line(10,10,35,100);
      line(20,120,60,0);
      p1=mp(20,120);
      p2=mp(60,0);

      for(i=0;i<6;i++)
        edges.pb(mp(vec[(i+1)%6].ff-vec[i].ff, vec[(i+1)%6].ss-vec[i].ss));


      for(i=0;i<6;i++)
        normal.pb(mp( edges[i].ss * -1 , edges[i].ff ) );

      for(i=0;i<6;i++)
       num.pb( normal[i].ff * ( p1.ff-vec[i].ff)  + normal[i].ss * (p1.ss-vec[i].ss) );

      for(i=0;i<6;i++)
       denom.pb(-1 * ( normal[i].ff * (p2.ff- p1.ff) + normal[i].ss* (p2.ss- p1.ss ) ) );


       for(i=0;i<6;i++)
        t.pb(double(num[i])/double(denom[i]));

      cout<<setw(20)<<"Edges"<<setw(20)<<"Normal"<<setw(10)<<"T"<<setw(10)<<"N"<<setw(10)<<"D"<<endl;
      for(i=0;i<6;i++)
       cout<<setw(10)<<edges[i].ff<<setw(10)<<edges[i].ss<<setw(10)<<normal[i].ff<<setw(10)<<normal[i].ss<<setw(10)<<t[i]<<setw(10)<<num[i]<<setw(10)<<denom[i]<<endl;
       getch();
       closegraph();
}
