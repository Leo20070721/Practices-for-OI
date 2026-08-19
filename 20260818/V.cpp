#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
int N,MOD,ST[200005][19],n,lst;

int query(int L,int R){
	int k=__lg(R-L+1);
	return max(ST[R][k],ST[L+(1<<k)-1][k]);
}
void insert(int p,int x){
	ST[p][0]=x;
	for(int i=1;p-(1<<i)>=0;i++)
		ST[p][i]=max(ST[p][i-1],ST[p-(1<<(i-1))][i-1]);
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>MOD;
	for(int i=1;i<=N;i++){
		char op;int x;
		cin>>op>>x;
		if(op=='Q'){
			lst=query(n-x+1,n);
			cout<<lst<<"\n";
		}
		else insert(++n,(x+lst)%MOD);
	}

	return 0;
}



