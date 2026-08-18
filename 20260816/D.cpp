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
int T;

int func(int q){
	int re=0;
	while(q>0){
		if(!(q&1)) return re;
		re++;q>>=1;
	}
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		int N;cin>>N;
		
		int nim=0;
		for(int i=1;i*2<=N;i++){
			int a,b;cin>>a>>b;
			int sg=func((a-1)|(b-1));
			nim^=sg;
		}
		
		if(nim) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}



