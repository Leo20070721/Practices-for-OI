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
int N,A,B,C,DP[4005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>A>>B>>C;
	for(int i=0;i<=N;i++){
		if(DP[i]==0 && i!=0) continue;
		if(i+A<=N) DP[i+A]=max(DP[i+A],DP[i]+1);
		if(i+B<=N) DP[i+B]=max(DP[i+B],DP[i]+1);
		if(i+C<=N) DP[i+C]=max(DP[i+C],DP[i]+1);
	}
	
	//for(int i=1;i<=N;i++) cout<<DP[i]<<" ";
	
	cout<<DP[N]<<"\n";

	return 0;
}



