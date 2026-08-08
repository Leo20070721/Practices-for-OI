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
int DP[100005],H[100005],N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	memset(DP,0x7f,sizeof(DP));
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>H[i];
	}
	
	DP[1]=0;
	for(int i=1;i<=N;i++){
		DP[i+1]=min(DP[i+1],DP[i]+abs(H[i]-H[i+1]));
		DP[i+2]=min(DP[i+2],DP[i]+abs(H[i]-H[i+2]));
	}
	
	cout<<DP[N]<<"\n";

	return 0;
}



