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
int N,M;
vector<int> amap[100005];
bool vis[100005];

void DFS(int now){
	vis[now]=true;
	cout<<now<<" ";
	for(unsigned int i=0;i<amap[now].size();i++)
		if(!vis[amap[now][i]]) DFS(amap[now][i]);
}

queue<int> Q;
void BFS(int bgn){
	Q.push(bgn);vis[bgn]=true;
	while(!Q.empty()){
		int now=Q.front();Q.pop();		
		cout<<now<<" ";
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i];
			if(!vis[nxt]){
				vis[nxt]=true;
				Q.push(nxt);
			}
		}			
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int f,t;cin>>f>>t;
		amap[f].push_back(t);
	}
	for(int i=1;i<=N;i++) sort(amap[i].begin(),amap[i].end());
	
	DFS(1);cout<<"\n";
	memset(vis,0,sizeof(vis));
	BFS(1);cout<<"\n"; 

	return 0;
}



