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
const int MAXS=2e6+12;
int N,M;
vector<int> amap[MAXS];

int scc[MAXS];
int low[MAXS],dfn[MAXS],T;
int cnt;bool vis[MAXS];
stack<int> Q;
void Tarjan(int now){
	dfn[now]=low[now]=++T;
	Q.push(now);vis[now]=true;
	for(unsigned int i=0;i<amap[now].size();i++){
		int nxt=amap[now][i];
		if(!dfn[nxt]){
			Tarjan(nxt);
			low[now]=min(low[now],low[nxt]);
		}else if(vis[nxt]) low[now]=min(low[now],dfn[nxt]);
	}
	
	if(dfn[now]==low[now]){
		int cur; cnt++;
		do{
			cur=Q.top();Q.pop();
			vis[cur]=false;
			scc[cur]=cnt;
		}while(cur!=now);		
	}
}
 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int _i=1;_i<=M;_i++){
		int i,a,j,b;cin>>i>>a>>j>>b;
		amap[i+(a?N:0)].push_back(j+(b?0:N));
		amap[j+(b?N:0)].push_back(i+(a?0:N));
	}
	
	for(int i=1;i<=2*N;i++)
		if(!dfn[i]) Tarjan(i);
		
	for(int i=1;i<=N;i++){
		if(scc[i]!=scc[i+N]) continue;
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	
	cout<<"POSSIBLE\n";
	for(int i=1;i<=N;i++){
		if(scc[i]<scc[i+N]) cout<<"1 ";
		else                cout<<"0 ";
	}cout<<"\n";

	return 0;
}



