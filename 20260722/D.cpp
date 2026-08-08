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
int N,DP[105][3]; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	memset(DP,0x7f,sizeof(DP));
	DP[0][0]=DP[0][1]=DP[0][2]=0;
	for(int i=1;i<=N;i++){
		int A;cin>>A;
		int slept=min(min(DP[i-1][0],DP[i-1][1]),DP[i-1][2]);
		switch(A){
			case 0:{
				DP[i][0]=slept+1;
				break;
			}
			case 1:{
				DP[i][0]=slept+1;
				DP[i][2]=min(DP[i-1][0],DP[i-1][1]);
				break;
			}
			case 2:{
				DP[i][0]=slept+1;
				DP[i][1]=min(DP[i-1][0],DP[i-1][2]);
				break;
			}
			case 3:{
				DP[i][0]=slept+1;
				DP[i][1]=min(DP[i-1][0],DP[i-1][2]);
				DP[i][2]=min(DP[i-1][0],DP[i-1][1]);
				break;
			}
		}
	}
	
	cout<<min(min(DP[N][0],DP[N][1]),DP[N][2])<<"\n";

	return 0;
}



