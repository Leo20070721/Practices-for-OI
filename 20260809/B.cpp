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
const int MAXS=2e5+12;
vector<int> head,nxt,to;
void addEdge(int f,int t){
	nxt.push_back(head[f]);
	head[f]=to.size();
	to.push_back(t);
} 

int dfn[MAXS],low[MAXS],T;
bool vis[MAXS];
set<int> cut;
void Tarjan(int now,int fa){
	dfn[now]=low[now]=++T;
	bool faFlag=false;
	vis[now]=true;
	
	for(int i=head[now];~i;i=nxt[i]){
		int t=to[i];
		if(!dfn[t]){
			Tarjan(t,now);
			if(low[t] > low[now]){
				cut.insert(i);
				if(i%2) cut.insert(i-1);
				else    cut.insert(i+1);
			}
			low[now]=min(low[now],low[t]);
		}else{
			if(t==fa && !faFlag) faFlag=true;
			else low[now]=min(low[now],dfn[t]);
		}		
	}
}

vector<int> ans[MAXS];
int cnt;
void DFS(int now){
	ans[cnt].push_back(now);
	vis[now]=true;
	for(int i=head[now];~i;i=nxt[i]){
		int t=to[i];
		if(cut.find(i)!=cut.end()) continue;
		if(vis[t]) continue;
		DFS(t);
	}
}

int N,M;
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
	
	for(int i=0;i<N;i++){
		if(!vis[i]) Tarjan(i,i);
	}
	//cout<<"cut:"<<cut.size()/2<<"\n";
	memset(vis,false,sizeof(vis));
	for(int i=0;i<N;i++){
		if(vis[i]) continue;
		//cout<<"DFS:"<<i<<"\n";
		cnt++;
		DFS(i);
	}
	
	cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++){
		cout<<ans[i].size()<<" ";
		for(unsigned int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}



