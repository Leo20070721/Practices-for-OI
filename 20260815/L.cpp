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
lli num[1025],ans;
int now;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	string sget;cin>>sget;
	num[0]++;
	for(unsigned int i=0;i<sget.size();i++){
		int iget=sget[i]-'0';
		now^=(1<<iget);
		num[now]++;
	}
	
	for(int i=0;i<1024;i++)
		ans+=num[i]*(num[i]-1)/2;
	
	cout<<ans<<"\n";

	return 0;
}



