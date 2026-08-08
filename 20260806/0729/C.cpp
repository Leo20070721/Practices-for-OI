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
int N,K;
lli subDP[100005],sum,ans;
deque< pair<int,lli> > minn; 

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++){
		lli a;cin>>a;
		sum+=a;
		while(!minn.empty() && minn.front().first<=i-K) minn.pop_front();
		while(!minn.empty() && minn.back().second>a) minn.pop_back();
		minn.push_back(make_pair(i,a));
		
		subDP[i]=minn.front().second+a;		
	}
	
	for(int i=N;i>=N-K;i--) ans=max(ans,sum-subDP[i]);
	cout<<ans<<"\n";

	return 0;
}



