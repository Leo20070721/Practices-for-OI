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
const int MAXN=5e5+12,MAXM=2e6+24;
int N,M;
vector<int> head,nxt,to;
void addEdge(int f,int t){
	nxt.push_back(head[f]);
	head[f]=to.size();
	to.push_back(t);
}

stack<int> tree;
vector<int> ans[MAXN];int cnt;
int dfn[MAXN],low[MAXN],T;
void Tarjan(int now,int fa){
	int subtree=0;
	dfn[now]=low[now]=++T;
	tree.push(now);
	
	for(int i=head[now];~i;i=nxt[i]){
		int t=to[i];
		if(!dfn[t]){
			subtree++;
			Tarjan(t,now);
			if(low[t]>=dfn[now]){
				cnt++;
				while(!tree.empty() && tree.top()!=t){
					ans[cnt].push_back(tree.top());
					tree.pop();
				}
				ans[cnt].push_back(tree.top());
				tree.pop();
				ans[cnt].push_back(now);
			}
			low[now]=min(low[now],low[t]);
		}else low[now]=min(low[now],dfn[t]);
	}
	
	if(now==fa && subtree==0){
		cnt++;
		ans[cnt].push_back(now);
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
		if(!dfn[i]) Tarjan(i,i);
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



