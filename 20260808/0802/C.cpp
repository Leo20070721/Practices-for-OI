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
lli exgcd(lli a,lli b,lli &x,lli &y){
	if(b==0){
		x=1,y=0;return a;
	}
	lli re=exgcd(b,a%b,x,y);
	tie(x,y)=make_tuple(y,x-(a/b)*y);
	return re;
} 

lli A,B,x,y;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>A>>B;
	exgcd(A,B,x,y);
	cout<<(x%B+B)%B<<"\n";


	return 0;
}



