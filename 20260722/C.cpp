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
int DP[100005][3],N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N;
	for(int i=1;i<=N;i++){
		int a,b,c;cin>>a>>b>>c;
		DP[i][0]=max(DP[i-1][1],DP[i-1][2])+a;
		DP[i][1]=max(DP[i-1][0],DP[i-1][2])+b;
		DP[i][2]=max(DP[i-1][0],DP[i-1][1])+c;
	}
	
	cout<<max(max(DP[N][0],DP[N][1]),DP[N][2])<<"\n";


	return 0;
}



