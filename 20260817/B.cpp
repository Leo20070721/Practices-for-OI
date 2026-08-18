#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
inline void _OpenFiles(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
Ld line[3],x[3],y[3],s; 
Ld length(Ld x1,Ld y1,Ld x2,Ld y2)
	{return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	for(int i=0;i<3;i++) cin>>x[i]>>y[i];
	for(int i=0;i<3;i++){
		line[i]=length(x[i],y[i],x[(i+1)%3],y[(i+1)%3]);
		s+=line[i];
	}s/=2;
	
	Ld ans=sqrt(s*(s-line[0])*(s-line[1])*(s-line[2]));
	int fin=round(ans);
	cout<<fin<<"\n";

	

	return 0;
}



