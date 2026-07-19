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
int N,M,amap[52][3],ans=5000;

int calc(int a,int b){
	int nans=0;
	for(int i=1;i<=a;i++){
		nans+=amap[i][1]+amap[i][2];
	}
	for(int i=a+1;i<=b;i++){
		nans+=amap[i][0]+amap[i][2];
	}
	for(int i=b+1;i<=N;i++){
		nans+=amap[i][0]+amap[i][1];
	}
	return nans;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		for(int j=0;j<M;j++){
			if     (sget[j]=='W') amap[i][0]++;
			else if(sget[j]=='B') amap[i][1]++;
			else                  amap[i][2]++;
		}
	}
	
	for(int i=1;i<=N-2;i++){
		for(int j=i+1;j<=N-1;j++){
			ans=min(ans,calc(i,j));
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}



