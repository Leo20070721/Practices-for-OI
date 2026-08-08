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
const int MAXL=1005;
int N,Q;
int sum[MAXL][MAXL]; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	

	cin>>N>>Q;
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		for(int j=1;j<=N;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(sget[j-1]=='*'?1:0);
		}
	}
	
//	cout<<"\n";
//	for(int i=1;i<=N;i++){
//		for(int j=1;j<=N;j++){
//			cout<<sum[i][j]<<" ";
//		}cout<<"\n";
//	}cout<<"\n";
		
	for(int i=1;i<=Q;i++){
		int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
		cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<"\n";
	}

	return 0;
}



