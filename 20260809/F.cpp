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
bool vis[MAXN],flag[MAXN];

vector<int> head,nxt,to;
void addEdge(int u,int v){
	nxt.push_back(head[u]);
	head[u]=to.size();
	to.push_back(v);
}

vector<int> ans;

int T;
void Tarjan(int now,int fa){
	int subtree=0;
	vis[now]=true;
	dfn[now]=low[now]=++T;
	
	for(int i=head[now];~i;i=nxt[i]){
		int t=to[i];
		if(!dfn[t]){
			subtree++;
			Tarjan(t,now);			
			if(fa!=now && low[t] >= dfn[now] && !flag[now]){
				ans.push_back(now);
				flag[now]=true;				
			}
			low[now]=min(low[now],low[t]);
		}else if(t!=fa){		
			low[now]=min(low[now],dfn[t]);				
		}
	}
	
	if(fa==now && subtree>1){
		ans.push_back(now);
		flag[now]=true;	
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
	
	cout<<ans.size()<<"\n";
	for(unsigned int i=0;i<ans.size();i++){
		cout<<ans[i]<<"\n";
	}

	return 0;
}



