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
int T,M,DP[1005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T>>M;
	for(int i=1;i<=M;i++){
		int t,v;cin>>t>>v;
		for(int i=T-t;i>=0;i--){
			DP[i+t]=max(DP[i+t],DP[i]+v);
		}
	}
	
	cout<<DP[T]<<"\n";

	return 0;
}



