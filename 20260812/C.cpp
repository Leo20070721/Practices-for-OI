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
const int MAXN=1e5+12;
int N,Q;

vector<int> amap[MAXN];
int dfn[MAXN],dep[MAXN],root[MAXN][18],T;
int get(int x,int y){return dfn[x]<dfn[y]? x:y;}
void DFS(int now,int dad){
	dfn[now]=++T;
	dep[now]=dep[dad]+1;	
	root[T][0]=dad;
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

int length(int a,int b){
	int lca=LCA(a,b);
	return dep[a]+dep[b]-2*dep[lca];
}

bool check(int x,int y,int q){
	return ( length(x,y)==length(x,q)+length(y,q) );
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>Q;
	for(int i=1;i<N;i++){
		int a,b;cin>>a>>b;
		amap[a].push_back(b);
		amap[b].push_back(a);
	}
	
	dep[0]=0;
	DFS(1,0);
	
	for(int i=1;i<=__lg(N);i++){
		for(int j=1;j+(1<<(i-1))<=N;j++){
			root[j][i]=get(root[j][i-1],root[j+(1<<(i-1))][i-1]);
		}
	}
	
	while(Q--){
		int a,b,c,d;cin>>a>>b>>c>>d;
		int lca1=LCA(a,b),lca2=LCA(c,d);
		if(check(a,b,lca2)||check(c,d,lca1)) cout<<"Y\n";
		else cout<<"N\n";
	}

	return 0;
}



