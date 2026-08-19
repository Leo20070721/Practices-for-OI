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
int N,T; 
int A[100005],bgn=1,now;
int ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>T;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		now+=A[i];
		while(now>T && bgn<=i){
			now-=A[bgn];bgn++;
		}
		ans=max(ans,i-bgn+1);
	}
	
	cout<<ans<<"\n";

	return 0;
}



