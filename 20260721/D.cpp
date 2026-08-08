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
const int MAXL=200005;
int N;
lli sum[MAXL],ans,K;
unordered_map <lli,lli> cache;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>K;
	cache[0]++;
	for(int i=1;i<=N;i++){
		lli lget;cin>>lget;
		sum[i]=sum[i-1]+lget;
		ans+=cache[sum[i]-K];
		cache[sum[i]]++;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}



