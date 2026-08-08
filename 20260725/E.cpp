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
lli N,X,DP[1000005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	memset(DP,0x7f,sizeof(DP));
	DP[0]=0;

	cin>>N>>X;
	for(int i=1;i<=N;i++){
		int c;cin>>c;
		for(int j=0;j<=X-c;j++){
			DP[j+c]=min(DP[j+c],DP[j]+1);
		}		
	}
	

	if(DP[X]<=X){cout<<DP[X]<<"\n";}
	else cout<<"-1\n";
	

	return 0;
}

