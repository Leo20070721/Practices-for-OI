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
bool amap[1005][1005];
vector<int> bmap[1005]; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int a,b;cin>>a>>b;
		amap[a][b]=true;
		amap[b][a]=true; 
		bmap[a].push_back(b);
		bmap[b].push_back(a);
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) cout<<amap[i][j]<<" ";
		cout<<"\n";
	}
	for(int i=1;i<=N;i++){
		sort(bmap[i].begin(),bmap[i].end());
		cout<<bmap[i].size()<<" ";
		for(unsigned int j=0;j<bmap[i].size();j++) cout<<bmap[i][j]<<" ";
		cout<<"\n";
	}

	return 0;
}



