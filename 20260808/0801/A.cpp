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

lli quick_pow(lli a,lli x,lli p){
	lli re=1,now=a;
	while(x>0){
		if(x&1) re*=now;
		now*=now;
		x>>=1;
		
		re%=p;
		now%=p;
	}
	return re;
}

int A,B,P;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>A>>B>>P;
	cout<<A<<"^"<<B<<" mod "<<P<<"="<<quick_pow(A,B,P)<<"\n";

	return 0;
}



