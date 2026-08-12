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
const int MAXS=1e5+12;
struct Node{
	int pos;
	int dis;	
	
	bool operator< (const Node &a)const{
		return dis>a.dis;
	}
};
priority_queue<Node> Q;
vector<Node> amap[MAXS];

int N,M,S,T;

int dis[MAXS];bool vis[MAXS];
void Dijkstra(int bgn){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));	
	dis[bgn]=0;
	Q.push({bgn,0});
	
	while(!Q.empty()){
		int now=Q.top().pos;Q.pop();
		if(vis[now]) continue;
		vis[now]=true;
		
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i].pos;
			if(dis[nxt]>dis[now]+amap[now][i].dis){
				dis[nxt]=dis[now]+amap[now][i].dis;
				Q.push({nxt,dis[nxt]});
			}
		}
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M>>S>>T;
	for(int i=1;i<=M;i++){
		int f,t,v;cin>>f>>t>>v;
		amap[f].push_back({t,v});
		amap[t].push_back({f,v});
	}
	
	Dijkstra(S);
	cout<<dis[T]<<"\n";

	return 0;
}



