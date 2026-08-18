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
priority_queue<lli, vector<lli>, greater<lli> > Q;
lli sub;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		int op;
		cin>>op;
		if(op==3){
			cout<<Q.top()+sub<<"\n";Q.pop();
		}else if(op==2){
			lli X;cin>>X;sub+=X;
		}else{
			lli X;cin>>X;Q.push(X-sub);
		}
	}

	return 0;
}



