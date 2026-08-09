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
const int MAXS=5e6+24;
lli M,N,T,MAXN,MOD=998244353;
lli f[MAXS],inv[MAXS],finv[MAXS],ans;

void init(){
	f[0]=f[1]=inv[0]=inv[1]=finv[0]=finv[1]=1;
	for(int i=2;i<=MAXN+1;i++){
		f[i]=f[i-1]*i%MOD;
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T>>MAXN;
	init();
	while(T--){
		cin>>N>>M;
		ans^=(f[N]*finv[M]%MOD)*finv[N-M]%MOD;
	}
	cout<<ans<<"\n";

	return 0;
}



