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
int N,T[100005];
int L,R,LT,RT;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>T[i];
	
	L=0,R=N+1;
	while(L+1<R){		
		while(L+1<R && LT<=RT){
			LT+=T[++L];
		}
		while(L<R-1 && LT>RT){
			RT+=T[--R];
		}
//		cout<<L<<","<<R<<"\n";
	}
	cout<<L<<" "<<N-L<<"\n";

	return 0;
}



