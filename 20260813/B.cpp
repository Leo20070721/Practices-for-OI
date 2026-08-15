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
int N,cnt;
vector<int>amap[200005];
bool vis[200005],flag;

void DFS(int now,int fa){
	cnt--;
	if(flag) return;
	if(vis[now]){flag=true;return;}
	vis[now]=true;
	for(int nxt:amap[now])
		if(nxt!=fa) DFS(nxt,now);
}

signed main(){
	if(_QuickStream) _QuickStreamOpen();

	cin>>N;cnt=N;
	for(int i=1;i<N;i++){
		int a,b;cin>>a>>b;
		amap[a].push_back(b);
		amap[b].push_back(a);
	}
	
	DFS(1,1);
	
	if(!cnt) cout<<"Yes\n";
	else cout<<"No\n";


	return 0;
}

