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
lli DP[200005],a[200005],ans=-INT_MAX;
int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=N;i++){
		DP[i]=max(a[i],DP[i-1]+a[i]);
		ans=max(ans,DP[i]);
	}
	
	cout<<ans<<"\n";

	return 0;
}



