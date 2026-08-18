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
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N,A;
int DP[3];

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A;
		DP[2]=max(gcd(DP[2],A),gcd(DP[1],A));
		DP[1]=DP[0];
		DP[0]=gcd(DP[0],A);		
		//cout<<"i="<<i<<",A="<<A<<":"<<DP[0]<<" "<<DP[1]<<" "<<DP[2]<<"\n";
	}
	
	cout<<max(DP[0],max(DP[1],DP[2]))<<"\n";

	return 0;
}



