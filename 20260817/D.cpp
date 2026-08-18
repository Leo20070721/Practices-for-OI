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
int N,num;
Ld x[105],y[105]; 
int sgn(int a,int b,int c){
	Ld q=(x[b]-x[a])*(y[c]-y[b])-(y[b]-y[a])*(x[c]-x[b]);
	if(q>0) return 1;
	else if(q<0) return -1;
	else return 0;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>x[101]>>y[101]>>x[102]>>y[102];
	cin>>N;
	
	for(int i=0;i<N;i++) cin>>x[i]>>y[i];
	
	for(int i=0;i<N;i++)
		if((sgn(101,i,102)!=sgn(101,(i+1)%N,102))
		&& (sgn(i,101,(i+1)%N)!=sgn(i,102,(i+1)%N))) 
			num++;


	
	cout<<1+num/2<<"\n";	

	return 0;
}



