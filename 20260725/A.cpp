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
int DP[100005],h[100005],N,K;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	memset(DP,0x7f,sizeof(DP));
	DP[1]=0;
	cin>>N>>K;
	for(int i=1;i<=N;i++) cin>>h[i];
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=K;j++){
			DP[i+j]=min(DP[i+j],DP[i]+abs(h[i+j]-h[i]));
		}
	}
	
	cout<<DP[N]<<"\n";

	return 0;
}



