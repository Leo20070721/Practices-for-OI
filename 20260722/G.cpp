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
const int MOD=1e9+7,MAXN=1e5;
int T,K,DP[2*MAXN+24][2],sum[2*MAXN+24];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T>>K;
	
	DP[0][0]=1;
	for(int i=0;i<=MAXN;i++){
		DP[i+1][0]+=(DP[i][0]+DP[i][1])%MOD;
		DP[i+1][0]%=MOD; 
		DP[i+K][1]+=(DP[i][0]+DP[i][1])%MOD;
		DP[i+K][1]%=MOD; 
	}
	
//	for(int i=0;i<=24;i++){cout<<DP[i][0]<<" ";}cout<<"\n";
//	for(int i=0;i<=24;i++){cout<<DP[i][1]<<" ";}cout<<"\n";
	
	sum[0]=1;
	for(int i=1;i<=MAXN;i++){
		sum[i]=((sum[i-1]+DP[i][0])%MOD+DP[i][1])%MOD;
	}
		
	for(int i=1;i<=T;i++){
		int l,r;cin>>l>>r;
		cout<<(sum[r]-sum[l-1]+MOD)%MOD<<"\n"; 
	}

	return 0;
}



