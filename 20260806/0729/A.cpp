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
int DP[105][5000];
int sum[105][5000]; 
int N,K;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>K;
	DP[1][0]=1;
	for(int i=0;i<=K;i++)sum[1][i]=1;
	
	for(int i=2;i<=N;i++){
		for(int j=0;j<=K;j++){
//			for(int p=1;p<=i;p++){
//				if(j-(i-p) < 0) continue;
//				DP[i][j]+=DP[i-1][j-(i-p)];//j-i+1 -> j
//				DP[i][j]%=10000;
//			}
			if(j-i<0) DP[i][j]=sum[i-1][j];
			else DP[i][j]=sum[i-1][j]-sum[i-1][j-i];
			DP[i][j]=(DP[i][j]+10000)%10000;
		}
		sum[i][0]=DP[i][0];
		for(int k=1;k<=K;k++) {
			sum[i][k]=sum[i][k-1]+DP[i][k];
			sum[i][k]%=10000;
		}
	}
	
	cout<<(sum[N][K]-sum[N][K-1]+10000)%10000<<"\n";
//	cout<<DP[N][K]<<"\n"<<sum[N][K]<<"\n"<<sum[N][K-1]<<"\n\n";
//	
//	for(int i=0;i<=N;i++){
//		for(int j=1;j<=K;j++){
//			cout<<DP[i][j]<<" ";
//		}cout<<"\n";
//	}

	return 0;
}



