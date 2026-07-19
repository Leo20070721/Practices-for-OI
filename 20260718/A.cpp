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
int N,M;

lli sqr(int a,int b){
	int maxl=min(a,b);
	lli ans=0;
	for(int i=1;i<=maxl;i++){
		ans += (a-i+1)*(b-i+1);
	}
	return ans;
}

lli lsqr(int a,int b){
	lli ans=0;	
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			ans += (a-i+1)*(b-j+1);
		}
	}
	return ans;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N>>M;
	cout<<sqr(M,N)<<" "<<lsqr(M,N)-sqr(M,N)<<"\n";


	return 0;
}



