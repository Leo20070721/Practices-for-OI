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
const int MAXN=1e5+12,MAXM=5e5+24;
int N,M,dfn[MAXN],low[MAXN];
bool vis[MAXN];

vector<int> head,nxt,to;
void addEdge(int u,int v){
	nxt.push_back(head[u]);
	head[u]=to.size();
	to.push_back(v);
}

struct Edge{
	int from,to,no;
	Edge(){from=to=no=0;}
	Edge(int f,int t,int n){
		from=f;to=t;no=n;
	}
	
	bool operator< (const Edge &a)const{
		return no<a.no;
	}
};
vector< Edge > ans;

int T;
void Tarjan(int now,int fa){
	vis[now]=true;
	bool flag=false;
	dfn[now]=low[now]=++T;
	
	for(int i=head[now];~i;i=nxt[i]){
		int t=to[i];
		if(!dfn[t]){
			Tarjan(t,now);			
			if(low[t] > dfn[now]){
				if(i%2) ans.push_back(Edge(t,now,i-1));
				else    ans.push_back(Edge(now,t,i));
			}
			low[now]=min(low[now],low[t]);
		} else{
			if(t == fa && !flag) flag=true;			
			else low[now]=min(low[now],dfn[t]);				
		}
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	head.resize(N+4,-1);
	
	for(int i=1;i<=M;i++){
		int f,t;cin>>f>>t;
		addEdge(f,t); 
		addEdge(t,f); 
	}
	
	for(int i=1;i<=N;i++){
		if(!vis[i]) Tarjan(i,i);
	}
	
	sort(ans.begin(),ans.end());
	
	//cout<<"------------\n"; 
	
	for(unsigned int i=0;i<ans.size();i++){
		cout<<ans[i].from<<" "<<ans[i].to<<"\n";
	}

	return 0;
}



