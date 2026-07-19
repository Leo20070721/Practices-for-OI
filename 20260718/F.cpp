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
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N;
int ans[10];
bool vis[10];

void dfs(int dep,bool nvis[],int nans[]){
	if(dep==N+1){
		for(int i=1;i<=N;i++){
			printf("%5d",nans[i]);
		}printf("\n");
		return;
	}
	
	for(int i=1;i<=N;i++){
		if(nvis[i]) continue;
		nvis[i]=true;
		nans[dep]=i;
		dfs(dep+1,nvis,nans);
		nvis[i]=false;
	}
	return;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N;
	
	dfs(1,vis,ans);

	return 0;
}



