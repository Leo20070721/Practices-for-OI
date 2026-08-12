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
const int MAXN=5e5+12;
int N,M,S; 
vector<int> amap[MAXN];

int dfn[MAXN],fa[MAXN][20],T;
int get(int x,int y){return dfn[x]<dfn[y]? x:y;}
void DFS(int now,int dad){
	dfn[now]=++T;
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

	cin>>N>>M>>S;
	for(int i=1;i<N;i++){
		int a,b;cin>>a>>b;
		amap[a].push_back(b);
		amap[b].push_back(a);
	}
	
	DFS(S,0);
	for(int i=1;i<=__lg(N);i++){
		for(int j=1;j+(1<<i)-1<=N;j++){
			fa[j][i]=get(fa[j][i-1], fa[j+(1<<(i-1))][i-1]);
		}
	}
	
	while(M--){
		int a,b;cin>>a>>b;
		cout<<LCA(a,b)<<"\n";
	}

	return 0;
}



