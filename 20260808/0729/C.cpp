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
int N,K,A[100005];
lli subDP[100005],sum,ans=LLONG_MAX;
deque< pair<int,lli> >minn; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>K;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		sum+=A[i];
	}
	
	minn.push_back(make_pair(0,0ll));
	for(int i=1;i<=N;i++){
		while(!minn.empty() && minn.front().first+K+1<i) minn.pop_front();		
		
		subDP[i]=A[i];
		if(!minn.empty()) subDP[i]+=minn.front().second;
		
		while(!minn.empty() && minn.back().second>subDP[i]) minn.pop_back();
		minn.push_back(make_pair(i,subDP[i]));
	}
	
	for(int i=N;i>=N-K;i--){
		ans=min(ans,subDP[i]);
	}
	cout<<sum-ans<<"\n";

	return 0;
}



