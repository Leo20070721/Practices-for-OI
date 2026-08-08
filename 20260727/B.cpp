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
const int MAXS=1e9+5;
int N,Q;
lli sub[MAXS],num[MAXS],sum[MAXS];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>Q;
	for(int i=1;i<=N;i++){
		int l,r;lli v;cin>>l>>r>>v;
		sub[l]+=v;sub[r+1]-=v;
	}
	for(int i=1;i<=MAXS;i++){
		num[i]=num[i-1]+sub[i];
		sum[i]=sum[i-1]+num[i];
	}
	for(int i=1;i<=Q;i++){
		int l,r;cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<"\n";
	}
	

	return 0;
}



