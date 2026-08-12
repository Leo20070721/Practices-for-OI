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
int dfn[MAXN],dep[MAXN],root[MAXN][18],fa[MAXN][18],T;
int get(int x,int y){return dfn[x]<dfn[y]? x:y;}
void DFS(int now,int dad){
	dfn[now]=++T;
	dep[now]=dep[dad]+1;	
	root[T][0]=dad;
	fa[now][0]=dad;
	for(int i=1;i<=__lg(dep[now]);i++)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int nxt:amap[now])
		if(nxt!=dad) DFS(nxt,now);
}
int LCA(int a,int b){
	if(a==b) return a;
	a=dfn[a],b=dfn[b];
	if(a<b) swap(a,b);
	int d=__lg(a-b);
	return get(root[b+1][d],root[a-(1<<d)+1][d]);
}

int L,Ldep,R,Rdep;
void findD(int now,int dep,int fa,int &side,int &sidedep){
	if(dep>sidedep){sidedep=dep;side=now;}
	for(int nxt:amap[now])
		if(nxt!=fa) findD(nxt,dep+1,now,side,sidedep);
}

int jump(int from,int len){
	for(int i=0;len;i++,len>>=1)
		if(len&1) from=fa[from][i]; 
	return from;
}

bool solve(int u,int k,int t){
	int lca=LCA(u,t);
	if(dep[u]+dep[t]-2*dep[lca]<k) return false;
	
	if(dep[u]-dep[lca]>=k) cout<<jump(u,k)<<"\n";
	else cout<<jump(t,dep[u]+dep[t]-2*dep[lca]-k)<<"\n";
	return true;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<N;i++){
		int a,b;cin>>a>>b;
		amap[a].push_back(b);
		amap[b].push_back(a);
	}
	
	dep[0]=0;
	DFS(1,0);
	findD(1,1,0,L,Ldep);
	findD(L,1,0,R,Rdep);
	
	for(int i=1;i<=__lg(N);i++){
		for(int j=1;j+(1<<(i-1))<=N;j++){
			root[j][i]=get(root[j][i-1],root[j+(1<<(i-1))][i-1]);
		}
	}
	
	cin>>Q;
	while(Q--){
		int u,k;cin>>u>>k;
		if(solve(u,k,L));
		else if(solve(u,k,R));
		else cout<<"-1\n";
	}

	return 0;
}



