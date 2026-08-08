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
const int MAXL=200005;
int sub[MAXL],num[MAXL],sum[MAXL];
int N,K,Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>K>>Q;
	for(int i=1;i<=N;i++){
		int l,r;cin>>l>>r;
		sub[l]++;sub[r+1]--;
	}
	for(int i=1;i<MAXL;i++){
		num[i]=num[i-1]+sub[i];
		if(num[i]>=K) sum[i]=1;
		sum[i]+=sum[i-1];
	}
	
	for(int i=1;i<=Q;i++){
		int a,b;cin>>a>>b;
		cout<<sum[b]-sum[a-1]<<"\n";
	}

	return 0;
}



