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
lli W;
lli DP[100024];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>W;
	for(int i=1;i<=N;i++){
		lli w,v;cin>>w>>v;
		for(lli i=W-w;i>=0;i--) DP[i+w]=max(DP[i+w],DP[i]+v);
	}
	
	cout<<DP[W]<<"\n";
	
	return 0;
}



