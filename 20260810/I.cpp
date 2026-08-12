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
int N,S,T;
struct Node{
	int pos;int dis;
};
vector<Node> amap[MAXS];
deque<int> Q;
int dis[MAXS];bool vis[MAXS];

void BinBFS(int bgn){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[bgn]=0;
	Q.push_back(bgn);
	
	while(!Q.empty()){
		int now=Q.front();Q.pop_front();
		if(vis[now]) continue;
		vis[now]=true;
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i].pos,d=amap[now][i].dis;
			if(dis[nxt]>dis[now]+d){
				dis[nxt]=dis[now]+d;
				if(d==0) Q.push_front(nxt);
				else     Q.push_back(nxt);
			}
		}
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>S>>T;
	for(int i=1;i<=N;i++){
		int K;cin>>K;
		for(int j=1;j<=K;j++){
			int iget;cin>>iget;
			if(j==1) amap[i].push_back({iget,0});
			else     amap[i].push_back({iget,1});
		}
	}
	
	BinBFS(S);
	if(dis[T]==dis[0]) cout<<"-1\n";
	else cout<<dis[T]<<"\n";

	return 0;
}



