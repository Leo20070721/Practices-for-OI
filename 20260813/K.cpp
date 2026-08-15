#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
const bool _QuickStream=true;
//-----------------------------------------
const int MAXN=2e5+24;
int N,M;
vector<int> amap[2][MAXN];
vector<lli> val[2][MAXN];

struct Node{
	int pos;lli dis;
	bool operator<(const Node& a)const{return dis>a.dis;}
};
priority_queue<Node> Q;
lli dis[2][MAXN];bool vis[MAXN];
void Dijkstra(int bgn,int mode){
	memset(vis,0,sizeof(vis));
	
	dis[mode][bgn]=0;
	Q.push({bgn,0});
	while(!Q.empty()){
		int now=Q.top().pos;Q.pop();
		if(vis[now]) continue;
		vis[now]=true;
		
		for(unsigned int i=0;i<amap[mode][now].size();i++){
			int nxt=amap[mode][now][i],len=val[mode][now][i];
			if(dis[mode][nxt]>dis[mode][now]+len){
				dis[mode][nxt]=dis[mode][now]+len;
				Q.push({nxt,dis[mode][nxt]});
			}
		}
	}
}

signed main(){
	if(_QuickStream) _QuickStreamOpen();

	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int f,t,v;cin>>f>>t>>v;
		amap[0][f].push_back(t);
		val[0][f].push_back(v);
		amap[1][t].push_back(f);
		val[1][t].push_back(v);
	}
	
	memset(dis,0x3f,sizeof(dis));
	lli INF=dis[0][0];
	Dijkstra(1,0);
	Dijkstra(N,1);
	
	for(int i=1;i<=N;i++){
		if(dis[0][i]==INF || dis[1][i]==INF) cout<<"-1\n";
		else cout<<dis[0][i]+dis[1][i]<<"\n";
	}
	
	return 0;
}

