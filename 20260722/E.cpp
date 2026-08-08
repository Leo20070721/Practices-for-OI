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
const int MOD=1e9+7;
bool stop[1005][1005];
int ans[1005][1005],H,W;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>H>>W;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			char cget;cin>>cget;
			stop[i][j]=(cget=='#'?1:0);
		}
	}
	
	ans[1][1]=1;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(stop[i][j] || (i==1 && j==1)) continue;
			ans[i][j]=(ans[i-1][j]+ans[i][j-1])%MOD;
		}
	}
	
	cout<<ans[H][W]<<"\n";

	return 0;
}



