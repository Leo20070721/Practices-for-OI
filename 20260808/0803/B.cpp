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
string sget;
int ans;

bool check(char q){
	if(q=='A') return true;
	if(q=='C') return true;
	if(q=='G') return true;
	if(q=='T') return true;
	return false;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>sget;int nans=0;
	for(unsigned int i=0;i<sget.size();i++){		
		if(check(sget[i])) nans++;
		else{
			ans=max(ans,nans);
			nans=0;
		}
	}
	ans=max(ans,nans);
	cout<<ans<<"\n";

	return 0;
}



