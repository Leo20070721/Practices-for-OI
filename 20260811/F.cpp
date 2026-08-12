#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
const int MAXN=1e5+12,MAXM=3e5+24,INF=1e18;
struct Edge{
	int a;int b;int v;
	bool operator< (const Edge& a)const{return v<a.v;}
}edge[MAXM];
bool slt[MAXM];

void Max(int& maxn,int& subn,int q){
	if(q>maxn){
		subn=maxn;
		maxn=q;
	}else if(q!=maxn && q>subn) subn=q;
}

vector<int> tree[MAXN],val[MAXN];
int fa[MAXN][18],max1[MAXN][18],max2[MAXN][18],dep[MAXN];
void LCAinit(int now,int dad){
	fa[now][0]=dad;
	dep[now]=dep[dad]+1;
	
	for(int i=1;i<18;i++){
		int fafa=fa[now][i-1];
		fa[now][i]=fa[fafa][i-1];
		Max(max1[now][i],max2[now][i],max1[now][i-1]);
		Max(max1[now][i],max2[now][i],max2[now][i-1]);
		Max(max1[now][i],max2[now][i],max1[fafa][i-1]);
		Max(max1[now][i],max2[now][i],max2[fafa][i-1]);
	}
	
	for(unsigned int i=0;i<tree[now].size();i++){
		int nxt=tree[now][i],len=val[now][i];
		if(nxt==dad) continue;
		max1[nxt][0]=len;
		LCAinit(nxt,now);
	}
}

pair<int,int> LCA(int a,int b){
	int maxn=-INF,subn=-INF;
	if(dep[a]<dep[b]) swap(a,b);
	int sub=dep[a]-dep[b];
	for(int i=0;sub;i++,sub>>=1){
		if(sub&1){			
			Max(maxn,subn,max1[a][i]);
			Max(maxn,subn,max2[a][i]);
			a=fa[a][i];
		}
	}
	
	if(a==b) return make_pair(maxn,subn);
		
	for(int i=17;i>=0 && a!=b;i--){
		if(fa[a][i]!=fa[b][i]){			
			Max(maxn,subn,max1[a][i]);
			Max(maxn,subn,max2[a][i]);
			Max(maxn,subn,max1[b][i]);
			Max(maxn,subn,max2[b][i]);
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	Max(maxn,subn,max1[a][0]);
	Max(maxn,subn,max2[a][0]);
	Max(maxn,subn,max1[b][0]);
	Max(maxn,subn,max2[b][0]);
	return make_pair(maxn,subn);
}

int root[MAXN];
int findRoot(int x){return root[x]==x?x:root[x]=findRoot(root[x]);}
void merge(int x,int y){
	x=findRoot(x),y=findRoot(y);
	root[x]=y;
}

int N,M;
int ans,cnt;

void init(){for(int i=1;i<=N;i++) root[i]=i;}

void Kruskal(){
	for(int i=1;i<=M;i++){		
		int aroot=findRoot(edge[i].a),broot=findRoot(edge[i].b);
		if(aroot==broot) continue;
		merge(aroot,broot);
		cnt++;
		slt[i]=true;
		tree[edge[i].a].push_back(edge[i].b);
		tree[edge[i].b].push_back(edge[i].a);
		val[edge[i].a].push_back(edge[i].v);
		val[edge[i].b].push_back(edge[i].v);
		ans+=edge[i].v;
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
	for(int i=1;i<=N;i++){
		for(int j=0;j<18;j++){
			max1[i][j]=-INF;
			max2[i][j]=-INF;
		}
	}	
	
	LCAinit(1,1);
	
	if(_TEST>=5){
		cout<<"ans="<<ans<<"\n"<<"--------------------------\n";
		for(int i=1;i<=N;i++){
			cout<<i<<":";
			for(unsigned int j=0;j<tree[i].size();j++) 
				if(tree[i][j]!=fa[i][0])
					cout<<tree[i][j]<<" ";
			cout<<"\n";
		}cout<<"--------------------------\n";
		for(int i=1;i<=N;i++){
			cout<<i<<":";
			for(int j=0;j<17;j++) cout<<max1[i][j]<<" "; cout<<"\n  ";
			for(int j=0;j<17;j++) cout<<max2[i][j]<<" "; cout<<"\n"; 
		}cout<<"--------------------------\n";	
	}
	
	
	int fin=INF;
	for(int i=1;i<=M;i++){
		if(slt[i]) continue;
		if(edge[i].a==edge[i].b) continue;
		pair<int,int> pget=LCA(edge[i].a,edge[i].b);
		if(_TEST>=5)cout<<"check "<<edge[i].a<<"~"<<edge[i].b<<"="<<edge[i].v<<":maxn="<<pget.first<<" subn="<<pget.second<<"\n";
		if(edge[i].v!=pget.first){
			fin=min(fin,ans+edge[i].v-pget.first);
		}else{
			fin=min(fin,ans+edge[i].v-pget.second);
		}
	}
	
	cout<<fin<<"\n";	

	return 0;
}



