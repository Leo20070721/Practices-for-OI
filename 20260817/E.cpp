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
int N;
Ld x[105],y[105],ans;
Ld Xmult(int a,int b,int c){
	return (x[b]-x[a])*(y[c]-y[a])-(y[b]-y[a])*(x[c]-x[a]);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=0;i<N;i++) cin>>x[i]>>y[i];
	
	for(int i=1;i<N-1;i++)
		ans+=Xmult(0,i,i+1);
		
	int fin=round(ans);
	cout<<fin/2<<"\n";

	return 0;
}



