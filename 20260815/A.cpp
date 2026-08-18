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
lli A,B,C,D;

lli gcd(lli a,lli b){
	if(b==0) return a;
	return gcd(b,a%b);
}
 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>A>>B>>C>>D;
	lli lcm=C/gcd(C,D)*D;
	lli x1=(A-1)/C,y1=(A-1)/D,z1=(A-1)/lcm;
	lli x2=B/C,y2=B/D,z2=B/lcm;
	lli ans1=x1-z1+y1,ans2=x2-z2+y2;
	cout<<B-A+1-ans2+ans1<<"\n";

	return 0;
}



