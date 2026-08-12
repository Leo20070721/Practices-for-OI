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
const int MAXN=2e5+12; 
int N,Q;
vector<int> amap[MAXN];

int dfnin[MAXN],dfnout[MAXN],dep[MAXN],In,Out;
vector<int> sameIn[MAXN],sameOut[MAXN];
void DFS(int now,int dad){
	dfnin[now]=++In;
	dep[now]=dep[dad]+1;
	sameIn[dep[now]].push_back(In);
	for(int nxt:amap[now])
		if(nxt!=dad) DFS(nxt,now);
	dfnout[now]=++Out;
	sameOut[dep[now]].push_back(Out);
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=2;i<=N;i++){
		int iget;cin>>iget;
		amap[iget].push_back(i);
	}
	
	dep[0]=0;
	DFS(1,0);
	
	cin>>Q;
	while(Q--){
		int u,d;cin>>u>>d;
		int bgn=lower_bound(sameIn[d+1].begin(),sameIn[d+1].end(),dfnin[u])-sameIn[d+1].begin();
		int end=upper_bound(sameOut[d+1].begin(),sameOut[d+1].end(),dfnout[u])-sameOut[d+1].begin();
		if(end>bgn) cout<<end-bgn<<"\n";
		else cout<<"0\n";
	}

	return 0;
}	



