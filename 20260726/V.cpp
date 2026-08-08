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
int N,L,R;
lli DP[200005],a[200005],ans=-INT_MAX,vis[200005];
deque<pair<int,lli> > Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>L>>R;
	for(int i=0;i<=N;i++) cin>>a[i];
	
	vis[0]=true;
	for(int i=L;i<=N;i++){
		while(!Q.empty()){
			if(Q.front().first+R<i) {
				Q.pop_front();
			}else break;
		}
		while(!Q.empty()){
			if(Q.back().second<DP[i-L]) {
				Q.pop_back();
			}else break;
		}
		Q.push_back(make_pair(i-L,DP[i-L]));
		DP[i]=a[i]+Q.front().second;
		vis[i]=vis[Q.front().first];
		if(i+R>N && vis[i]) ans=max(ans,DP[i]);
	}
	
//	for(int i=0;i<=N;i++) cout<<DP[i]<<" ";
//	cout<<"\n";
	
	cout<<ans<<"\n";

	return 0;
}



