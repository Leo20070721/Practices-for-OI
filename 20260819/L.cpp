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
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		lli N;int re;
		cin>>N;
		cout<<"mul 999999999"<<endl; cin>>re;
		cout<<"digit"<<endl; cin>>re;
		if(N!=81) {cout<<"add "<<N-81<<endl; cin>>re;}
		cout<<"!"<<endl; cin>>re;
	}

	return 0;
}



