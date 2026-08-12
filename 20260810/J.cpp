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
const int MAXN=1e6+12;
int N,M;
priority_queue< pair<int,int> > IN;
struct Edge{
	int pos;int dis;
	bool operator< (const Edge& a)const{
		return dis>a.dis;
	} 
};
vector<Edge> amap[MAXN];

void read(){
	for(int i=1;i<=M;i++){
		int x,y;cin>>x>>y;
		IN.push(make_pair(x,y));
		IN.push(make_pair(y,x));
	}
	
	int f=IN.top().first,t=IN.top().second,cnt=0;
	while(!IN.empty()){
		pair<int,int> now=IN.top();IN.pop();
		if(f==now.first && t==now.second){
			cnt++;
			continue;
		}
		amap[f].push_back({t,cnt});
		f=now.first,t=now.second,cnt=1;
	}
	amap[f].push_back({t,cnt});
}

const int MOD=1e5+3;
int dis[MAXN],num[MAXN];bool vis[MAXN];
priority_queue<Edge> Q;
void Dijkstra(int bgn){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	dis[bgn]=0;num[bgn]=1;
	Q.push({bgn,0});
	
	while(!Q.empty()){
		int now=Q.top().pos;Q.pop();
		if(vis[now]) continue;
		vis[now]=true;
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i].pos,road=amap[now][i].dis;
			int newroad=(num[now]*road)%MOD;
			if(dis[nxt]==dis[now]+1){
				num[nxt]+=newroad;
				num[nxt]%=MOD;
			}
			else if(dis[nxt]>dis[now]+1){
				dis[nxt]=dis[now]+1;
				num[nxt]=newroad;
				Q.push({nxt,dis[nxt]});
			}
		}
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	read();
	
	Dijkstra(1);
	
	for(int i=1;i<=N;i++) cout<<num[i]<<"\n";

	return 0;
}



