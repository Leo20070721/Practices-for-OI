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
int N,M;
vector<int> amap[100005];
int ans[100005];

void DFS(int now){
	for(unsigned int i=0;i<amap[now].size();i++){
		int nxt=amap[now][i];
		if(ans[now]>ans[nxt]){
			ans[nxt]=ans[now];
			DFS(nxt);
		}
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int f,t;cin>>f>>t;
		amap[t].push_back(f);
	}
	for(int i=1;i<=N;i++) {
		ans[i]=i;
		sort(amap[i].begin(),amap[i].end());
	}		
	
	for(int i=N;i>0;i--) DFS(i);	
	for(int i=1;i<=N;i++) cout<<ans[i]<<" "; cout<<"\n";

	return 0;
}



