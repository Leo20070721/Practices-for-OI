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
lli a[300005],DP[300005][3],ans,X;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>X;
	for(int i=1;i<=N;i++) cin>>a[i];
	
	for(int i=1;i<=N;i++){
		DP[i][0]=max(DP[i-1][0]+a[i],0LL);
		DP[i][1]=max(DP[i][0],DP[i-1][1]+X*a[i]); 
		DP[i][2]=max(DP[i][1],DP[i-1][2]+a[i]);
		ans=max(ans,DP[i][2]);
	}
	
	cout<<ans<<"\n";

	return 0;
}



