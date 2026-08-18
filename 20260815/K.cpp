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
vector<int> x[100005],y[100005];
lli num[100005],ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			int col;cin>>col;
			x[col].push_back(i);
			y[col].push_back(j);
			num[col]++;
		} 
	}
	
	for(int i=1;i<=100000;i++){
		sort(x[i].begin(),x[i].end());
		sort(y[i].begin(),y[i].end());
	}
	
	for(int i=1;i<=100000;i++){
		for(int pos=1;pos<num[i];pos++)
			if(x[i][pos]!=x[i][pos-1])
				ans+=pos*(num[i]-pos)*(x[i][pos]-x[i][pos-1]);
		for(int pos=1;pos<num[i];pos++)
			if(y[i][pos]!=y[i][pos-1])
				ans+=pos*(num[i]-pos)*(y[i][pos]-y[i][pos-1]);	
	}
	
	cout<<ans<<"\n";

	return 0;
}



