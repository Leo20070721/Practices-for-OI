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
vector<int> amap[200005];
lli val[200005],ans,maxn,MOD=1e4+7;
bool vis[200005];
int N;

void DFS(int now){
	if(vis[now]) return;
	vis[now]=true;
	
	lli max1=0,max2=0,sum=0,sqrsum=0;
	for(unsigned int i=0;i<amap[now].size();i++){
		lli nval=val[amap[now][i]];
		if(nval > max1) max2=max1,max1=nval;
		else if(nval>max2) max2=nval;
		
		sum+=nval;sum%=MOD;
		sqrsum+=nval*nval;sqrsum%=MOD;
	}
	
	maxn=max(maxn,max1*max2);
	lli nans=(sum*sum)-sqrsum;
	nans%=MOD;
	nans=(nans+MOD)%MOD;
	ans+=nans;
	ans%=MOD;	
	
	for(unsigned int i=0;i<amap[now].size();i++){
		DFS(amap[now][i]);
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<N;i++){
		int u,v;cin>>u>>v;
		amap[u].push_back(v);
		amap[v].push_back(u);
	}
	for(int i=1;i<=N;i++) cin>>val[i];
	
	DFS(1);
	
	cout<<maxn<<" "<<ans<<"\n";

	return 0;
}



