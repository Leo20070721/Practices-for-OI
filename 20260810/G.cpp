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
int T;
int N,M;
struct Edge{
	int from;
	int to;
	int dis;
};
vector<Edge> edge;
lli dis[2005];
bool could[2005];
bool BellmanFord(int bgn){
	memset(dis,0x3f,sizeof(dis));
	memset(could,0,sizeof(could));
	const int INF=dis[2004];
	dis[bgn]=0;	could[bgn]=true;
	bool flag,can;
	
	for(int i=1;i<=N;i++){
		flag=false;can=false;
		for(unsigned int j=0;j<edge.size();j++){
			int f=edge[j].from,t=edge[j].to,d=edge[j].dis;
			if(dis[f]==INF) continue;
			if(could[f]) could[t]=true;
			if(dis[t]>dis[f]+d){				
				dis[t]=dis[f]+d;
				flag=true;
				if(could[f]) can=true;
//				cout<<"Relax:"<<f<<"->"<<t<<"="<<dis[t]<<"\n";
			}
		}
		if(!flag) break;
	}
	return (flag&&can);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		edge.clear();
		cin>>N>>M;		
		for(int i=1;i<=M;i++){
			int f,t,d;cin>>f>>t>>d;
			edge.push_back({f,t,d});
			if(d>=0) edge.push_back({t,f,d});
		}
		if(BellmanFord(1)) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}



