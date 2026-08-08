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
int N,M,T,in[5005],DP[5005][5005],pre[5005][5005];
vector<int> amap[5005],val[5005];
queue<int> Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M>>T;
	for(int i=1;i<=M;i++){
		int f,t,v;cin>>f>>t>>v;
		amap[f].push_back(t);
		val[f].push_back(v);
		in[t]++;
	}
	for(int i=1;i<=N;i++){
		if(in[i]==0) Q.push(i);
	}
	
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		for(unsigned int i=0;i<amap[now].size();i++){
			int nxt=amap[now][i],cost=val[now][i];
			
		}
	}

	return 0;
}



