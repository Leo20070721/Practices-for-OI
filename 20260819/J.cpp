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
		cout<<"digit"<<endl; cin>>re;
		cout<<"digit"<<endl; cin>>re;
		cout<<"add -8"<<endl; cin>>re;
		cout<<"add -4"<<endl; cin>>re;
		cout<<"add -2"<<endl; cin>>re;
		cout<<"add -1"<<endl; cin>>re;
		cout<<"add "<<N-1<<endl; cin>>re;
		cout<<"!"<<endl; cin>>re;
	}

	return 0;
}



