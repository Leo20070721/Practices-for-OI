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
lli C,A[200005],ans;
lli L,R,_L,_R;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>C;
	for(int i=1;i<=N;i++) cin>>A[i];
	sort(A+1,A+1+N);
	
	L=R=N;
	while(L>0){
		while(A[R]-A[L]<C && L>0) L--;
		if(L==0) break;
		if(A[R]-A[L]==C){
			_L=L; while(A[_L]==A[L] && _L>0) _L--;
			_R=R; while(A[_R]==A[R] && _R>L) _R--;
			ans+=(L-_L)*(R-_R);
//			cout<<ans<<":"<<L<<"-"<<_L<<","<<R<<"-"<<_R<<"\n"; 
			L=_L;R=_R;
		}		
		while(A[R]-A[L]>C && R>L) R--;
	}
	
	cout<<ans<<"\n"; 
	
	return 0;
}



