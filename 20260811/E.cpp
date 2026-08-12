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
const int MAXN=150+12;
int N,E,ans;
int L[MAXN],R[MAXN];
vector<int> amap[MAXN];
int depL[MAXN],depR[MAXN];
bool vis[MAXN];

bool DFS(int nowL){
	for(unsigned int i=0;i<amap[nowL].size();i++){
		int nowR=amap[nowL][i];
		if(depR[nowR]!=depL[nowL]) continue;
		depR[nowR]=-1;
		if(R[nowR]==0 || DFS(R[nowR])){
			R[nowR]=nowL;
			L[nowL]=nowR;
			return true; 
		}
	}
	return false;
}

set< pair<int,int> > road;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>E;
	for(int i=1;i<=E;i++){
		int f,t;cin>>f>>t;
		if(road.find(make_pair(f,t))==road.end()){
			amap[f].push_back(t);
			road.insert(make_pair(f,t));
		}		
	}

	while(true){
		//BFS
		queue<int> Q;int dt=INT_MAX;
		for(int i=1;i<=N;i++) depL[i]=-1;
		for(int i=1;i<=N;i++) depR[i]=-1;
		for(int i=1;i<=N;i++){
			if(L[i]==0){
				depL[i]=0;
				Q.push(i);
			}
		}
		while(!Q.empty()){
			int nowL=Q.front();Q.pop();
			if(depL[nowL]>dt) break;
			for(unsigned int i=0;i<amap[nowL].size();i++){
				int nowR=amap[nowL][i];
				if(depR[nowR]!=-1) continue;
				depR[nowR]=depL[nowL];
				if(R[nowR]==0) dt=depR[nowR]+1;
				else {
					int nxtL=R[nowR];
					depL[nxtL]=depR[nowR]+1;
					Q.push(nxtL);					
				}
			}
		}
		
		if(dt==INT_MAX) break;//没有未匹配R节点，最大匹配
		
		//DFS
		for(int i=1;i<=N;i++)
			if(L[i]==0) 
				if(DFS(i))
					ans++;			
	}
	
//	for(int i=1;i<=N;i++) cout<<L[i]<<" "; cout<<"\n";
//	for(int i=1;i<=N;i++) cout<<R[i]<<" "; cout<<"\n";
	for(int i=1;i<=N;i++){vis[L[i]] = true;}
	for(int i=1;i<=N;i++){
		if(vis[i]) continue;
		
		int nowL=i,nowR;
		do{
			vis[nowL]=true;
			nowR=L[nowL];
			cout<<nowL<<" ";
			nowL=nowR;
		}while(nowL!=0);
		cout<<"\n";
	}
	
	cout<<N-ans<<"\n";

	return 0;
}



