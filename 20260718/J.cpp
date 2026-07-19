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
const int MAXN=1000;
int N;
int val[10]={6,2,5,5,4,5,6,3,7,6}; 
int ans=0;

int calc(int a){
	if(a==0) return 6;
	int ans=0;
	while(a>0){
		ans+=val[a%10];
		a/=10;
	}
	return ans;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N;
	for(int i=0;i<=MAXN;i++){
		for(int j=i;j<=MAXN;j++){
			if(calc(i)+calc(j)+calc(i+j) == N-4){
				//cout<<i<<"+"<<j<<"="<<i+j<<"\n";
				if(i==j) ans++;
				else ans+=2;
			}
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}



