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
string sget; int Q;
bool res;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>sget>>Q;
	while(Q--){
		int op;cin>>op;
		if(op==1){
			res=!res;
		}else{
			int pos;char cget;
			cin>>pos>>cget;
			pos--;
			//cout<<pos<<"^"<<res<<"="<<(pos^res)<<"\n";
			if(pos^res) sget=sget+cget;
			else sget=cget+sget;
		}
	}
	
	
	if(res){
		for(int i=sget.size()-1;i>=0;i--) cout<<sget[i];
		cout<<"\n";
	}
	else cout<<sget<<"\n";

	return 0;
}



