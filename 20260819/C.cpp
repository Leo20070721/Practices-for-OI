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
int T,N,A[100005],ans;
int L[100005],R[100005];
int depL[100005],depR[100005];

bool DFS(int nowL){
	for(int i=1;i<=N;i++){
		if(nowL==i || A[nowL]==i) continue;
		int nowR=i;
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
	
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;i++) cin>>A[i];
		
		ans=0;
		for(int i=1;i<=N;i++) L[i]=R[i]=0;
	
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
				for(int i=1;i<=N;i++){
					if(nowL==i || A[nowL]==i) continue;
					int nowR=i;
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
		
		if(N!=ans) cout<<"Impossible\n";
		else{
			cout<<"Possible\n";
			for(int i=1;i<=N;i++){
				cout<<R[i]<<" ";
				L[A[R[i]]]=i;
			}cout<<"\n";
			for(int i=1;i<=N;i++) cout<<L[i]<<" "; cout<<"\n";
		}
			
	}

	return 0;
}



