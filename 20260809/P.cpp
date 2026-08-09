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
const int MAXS=5e5+12;
int N,M;

vector<int> head,nxt,to;
void addEdge(int f,int t){
	nxt.push_back(head[f]);
	head[f]=to.size();
	to.push_back(t);
}

int dfn[MAXS],low[MAXS],T;
stack<int> tree;
bool in[MAXS];
vector<int> ans[MAXS];int cnt;
void Tarjan(int now,int fa){
	tree.push(now);in[now]=true;
	dfn[now]=low[now]=++T;
	int subtree=0;
	
	for(int i=head[now];~i;i=nxt[i]){
		int t=to[i];
		if(!dfn[t]){
			subtree++;
			Tarjan(t,now);			
			low[now]=min(low[now],low[t]);
		}else if(in[t]) low[now]=min(low[now],dfn[t]);
	}
	
	if(low[now]==dfn[now]){
		cnt++;
		while(!tree.empty() && tree.top()!=now){
			ans[cnt].push_back(tree.top());
			in[tree.top()]=false;tree.pop();
		}
		ans[cnt].push_back(tree.top());
		in[tree.top()]=false;tree.pop();
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
	}
	
	for(int i=0;i<N;i++){
		if(!dfn[i]) Tarjan(i,i);
	}
	
	cout<<cnt<<"\n";
	for(int i=cnt;i>=1;i--){
		cout<<ans[i].size()<<" ";
		for(unsigned int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	
//	for(int i=0;i<N;i++) cout<<dfn[i]<<" "; cout<<"\n";
//	for(int i=0;i<N;i++) cout<<low[i]<<" "; cout<<"\n";

	return 0;
}



