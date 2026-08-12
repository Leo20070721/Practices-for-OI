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
const int MAXN=1e4+12,MAXM=5e4+24,INF=1e9;
struct Edge{
	int a;int b;int v;
	bool operator< (const Edge& a)const{return v>a.v;}
}edge[MAXM];

vector<int> tree[MAXN],val[MAXN];
int fa[MAXN][18],maxv[MAXN][18],dep[MAXN];
bool vis[MAXN];
void LCAinit(int now,int dad){
	vis[now]=true;
	fa[now][0]=dad;
	dep[now]=dep[dad]+1;
	
	for(int i=1;i<18;i++){
		int fafa=fa[now][i-1];
		fa[now][i]=fa[fafa][i-1];
		maxv[now][i]=min(maxv[now][i-1],maxv[fafa][i-1]);
	}
	
	for(unsigned int i=0;i<tree[now].size();i++){
		int nxt=tree[now][i],len=val[now][i];
		if(nxt==dad) continue;
		maxv[nxt][0]=len;
		LCAinit(nxt,now);
	}
}

int LCA(int a,int b){
	int maxn=INF;
	if(dep[a]<dep[b]) swap(a,b);
	int sub=dep[a]-dep[b];
	for(int i=0;sub;i++,sub>>=1){
		if(sub&1){	
			maxn=min(maxn,maxv[a][i]);
			a=fa[a][i];
		}
	}
	
	if(a==b) return maxn;
		
	for(int i=17;i>=0 && a!=b;i--){
		if(fa[a][i]!=fa[b][i]){	
			maxn=min(maxn, min(maxv[a][i],maxv[b][i]) );	
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	maxn=min(maxn, min(maxv[a][0],maxv[b][0]) );
	return maxn;
}

int root[MAXN];
int findRoot(int x){return root[x]==x?x:root[x]=findRoot(root[x]);}
void merge(int x,int y){
	x=findRoot(x),y=findRoot(y);
	root[x]=y;
}

int N,M;
int cnt;

void init(){for(int i=1;i<=N;i++) root[i]=i;}

void Kruskal(){
	for(int i=1;i<=M;i++){		
		int aroot=findRoot(edge[i].a),broot=findRoot(edge[i].b);
		if(aroot==broot) continue;
		merge(aroot,broot);
		cnt++;
		tree[edge[i].a].push_back(edge[i].b);
		tree[edge[i].b].push_back(edge[i].a);
		val[edge[i].a].push_back(edge[i].v);
		val[edge[i].b].push_back(edge[i].v);
		if(cnt==N-1) return;
	}
	return;
}


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}	
	
	cin>>N>>M;
	init();
	for(int i=1;i<=M;i++) cin>>edge[i].a>>edge[i].b>>edge[i].v;
	sort(edge+1,edge+1+M);
	Kruskal();
	for(int i=1;i<=N;i++)
		for(int j=0;j<18;j++)
			maxv[i][j]=INF;
	
	for(int i=1;i<=N;i++)
		if(!vis[i])	LCAinit(i,i);
	
	if(_TEST>=5){
		for(int i=1;i<=N;i++){
			cout<<i<<":";
			for(unsigned int j=0;j<tree[i].size();j++) 
				if(tree[i][j]!=fa[i][0])
					cout<<tree[i][j]<<" ";
			cout<<"\n";
		}cout<<"--------------------------\n";
		for(int i=1;i<=N;i++){
			cout<<i<<":";
			for(int j=0;j<17;j++){
				if(maxv[i][j]==INF) cout<<"-1 ";
				else cout<<maxv[i][j]<<" "; 
			}cout<<"\n  ";
		}cout<<"--------------------------\n";	
	}
	
	
	int Q;cin>>Q;
	while(Q--){
		int a,b;cin>>a>>b;
		if(findRoot(a)!=findRoot(b)) cout<<"-1\n";
		else cout<<LCA(a,b)<<"\n";
	}	

	return 0;
}



