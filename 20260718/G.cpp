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
int ans[10005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>ans[i];
	}
	for(int i=1;i<=M;i++){
		next_permutation(ans,ans+N);
	}
	
	for(int i=0;i<N;i++){
		cout<<ans[i]<<" ";
	}cout<<"\n";

	return 0;
}



