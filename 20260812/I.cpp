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
const int MAXN=2e5+12; 
int N,Q;
vector<int> amap[MAXN];

int dfn[MAXN],nfd[MAXN],fa[MAXN][20],T;
int get(int x,int y){return dfn[x]<dfn[y]? x:y;}
void DFS(int now,int dad){
	dfn[now]=++T;
	nfd[T]=now;
	fa[dfn[now]][0]=dad;
	for(int nxt:amap[now])
		if(nxt!=dad) DFS(nxt,now);
}

int LCA(int x,int y){
	if(x==y) return x;
	x=dfn[x],y=dfn[y];
	if(x<y) swap(x,y);
	int d=__lg(x-y);
	return get(fa[y+1][d],fa[x-(1<<d)+1][d]);
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>Q;
	for(int i=2;i<=N;i++){
		int iget;cin>>iget;
		amap[iget].push_back(i);
	}
	
	for(int i=1;i<=N;i++) sort(amap[i].begin(),amap[i].end());
	
	DFS(1,0);
	for(int i=1;i<=__lg(N);i++){
		for(int j=1;j+(1<<i)-1<=N;j++){
			fa[j][i]=get(fa[j][i-1], fa[j+(1<<(i-1))][i-1]);
		}
	}
	
	while(Q--){
		int u,k;cin>>u>>k;
		if(dfn[u]+k-1>N){
			cout<<"-1\n";
			continue;
		}
		int end=nfd[dfn[u]+k-1];
		int lca=LCA(u,end);
		//cout<<u<<"-"<<k<<":"<<end<<","<<lca<<"\n";		
		if(lca==u) cout<<end<<"\n";
		else cout<<"-1\n";
	}

	return 0;
}	



