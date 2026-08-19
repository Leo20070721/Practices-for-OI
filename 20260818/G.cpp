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
int N,K,A[50004],DP[50004],ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>K;
	for(int i=1;i<=N;i++) cin>>A[i];
	sort(A+1,A+1+N);
	A[N+1]=2e9;
	
	int L=1,R=0;
	for(;R<=N;L++,R++){
		while(A[R]-K>A[L]) L++;
		DP[R]=max(DP[R-1],R-L+1);
		while(A[R+1]-K<=A[L] && R<N){
			R++;
			DP[R]=max(DP[R-1],R-L+1);
		}
		ans=max(ans,DP[L-1]+R-L+1);
	}
//	for(int i=1;i<=N;i++) cout<<DP[i]<<" "; cout<<"\n";
	
	cout<<ans<<"\n";

	return 0;
}



