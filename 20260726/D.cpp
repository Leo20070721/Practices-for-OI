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
lli N,a[3005],DP[3005][3005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>a[i];
	
	for(int len=1;len<=N;len++){
		for(int i=1,j=len;j<=N;i++,j++){
			if((N-len)%2==0){
				DP[i][j]=max(DP[i+1][j]+a[i],DP[i][j-1]+a[j]);
			}else{
				DP[i][j]=min(DP[i+1][j]-a[i],DP[i][j-1]-a[j]);
			}
		}
	}
	
	cout<<DP[1][N]<<"\n";

	return 0;
}



