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
int N,M,A[1000006];
int L,R,cnt;int num[2003];
int ans,bgn,fin;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>A[i]; 
	
	ans=N;bgn=1;fin=N;
	for(L=1,R=1;R<=N;R++){
		if(num[A[R]]==0)cnt++;
		num[A[R]]++;
		while(num[A[L]]>1 && L<R){
			num[A[L]]--;
			L++;
		}
//		cout<<ans<<":"<<L<<","<<R<<"\n";
		if(ans>R-L+1 && cnt==M){
			ans=R-L+1;
			bgn=L,fin=R;
			
		}
	}
	
	cout<<bgn<<" "<<fin<<"\n";

	return 0;
}



