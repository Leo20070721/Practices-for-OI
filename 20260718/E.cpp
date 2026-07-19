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
int N,R;
int ans[25];

void dfs(int dep,int pos,int nans[]){
	if(dep==R+1){
		for(int i=1;i<=R;i++){
			printf("%3d",nans[i]);
		}printf("\n");
		return;
	}
	
	if(N-pos+1<R-dep+1) return;
	for(int i=pos;i<=N-R+dep;i++){
		nans[dep]=i;
		dfs(dep+1,i+1,nans);
	}
	return;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>R;
	
	dfs(1,1,ans);

	return 0;
}



