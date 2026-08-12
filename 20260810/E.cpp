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
lli amap[105][105];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) continue;
			amap[i][j]=INT_MAX;
		}
	}		
			
	for(int i=1;i<=M;i++){
		int a,b;lli v;cin>>a>>b>>v;
		amap[a][b]=min(amap[a][b],v);
		amap[b][a]=min(amap[b][a],v);	
	}
	
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				amap[i][j]=min(amap[i][j],amap[i][k]+amap[k][j]);
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<amap[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}



