#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
const bool _QuickStream=false;
//-----------------------------------------
const int MAXN=1e5+12;
int N;
vector< pair<int,int> > edge;
vector<int> amap[MAXN];
int dep[MAXN];

void DFS(int now,int fa){
	dep[now]=dep[fa]+1;
	for(int nxt:amap[now])
		if(nxt!=fa) DFS(nxt,now);
}

signed main(){
	if(_QuickStream) _QuickStreamOpen();

	cin>>N;
	for(int i=1;i<N;i++){
		int a,b;cin>>a>>b;
		edge.push_back(make_pair(a,b));
		amap[a].push_back(b);
		amap[b].push_back(a);
	}
	
	DFS(1,0);
	for(int i=0;i<N-1;i++){
		if(dep[edge[i].first]%2) cout<<"1\n";
		else cout<<"0\n";
	}

	return 0;
}

