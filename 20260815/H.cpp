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
int T,A[505],B[505];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>T;
	while(T--){
		int N;cin>>N;
		bool notup=false,same=true;
		cin>>A[1];
		for(int i=2;i<=N;i++){
			cin>>A[i];
			if(A[i]<A[i-1]) notup=true;
		}
		cin>>B[1];
		for(int i=2;i<=N;i++){
			cin>>B[i];
			if(B[i]!=B[i-1]) same=false;
		}
		
		if(notup && same) cout<<"No\n";
		else cout<<"Yes\n";
	}

	return 0;
}



