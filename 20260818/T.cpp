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
int N,M,ST[1000006][24];

int query(int L,int R){
	int k=__lg(R-L+1);
	return max(ST[L][k],ST[R-(1<<k)+1][k]);
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>ST[i][0];
	
	for(int j=1;j<=21;j++)
	for(int i=1;i+(1<<j)-1<=N;i++)
		ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
	
	for(int i=1;i<=M;i++){
		int l,r;cin>>l>>r;
		cout<<query(l,r)<<"\n";
	}

	return 0;
}



