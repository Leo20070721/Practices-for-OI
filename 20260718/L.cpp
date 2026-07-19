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
int S1,S2,S3,S4;
int A[24],B[24],C[24],D[24];
int ans;

int dfs(int pos,int L,int R,int T[]){
	if(pos==0) return max(L,R);
	return min(dfs(pos-1,L+T[pos],R,T) , dfs(pos-1,L,R+T[pos],T));
}

int work(int S,int T[]){
	sort(T+1,T+S+1);	
	return dfs(S,0,0,T);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>S1>>S2>>S3>>S4;
	for(int i=1;i<=S1;i++) cin>>A[i];
	for(int i=1;i<=S2;i++) cin>>B[i];
	for(int i=1;i<=S3;i++) cin>>C[i];
	for(int i=1;i<=S4;i++) cin>>D[i];
	
	
	ans=work(S1,A)+work(S2,B)+work(S3,C)+work(S4,D);
	cout<<ans<<"\n";

	return 0;
}



