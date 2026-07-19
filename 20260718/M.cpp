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
lli N,M,price[42],ans; 
vector<lli> ansA,ansB;

void dfs(int end,int pos,lli cost){
	if(pos==end+1){
		if(pos-1<=N/2) ansA.push_back(cost);
		else ansB.push_back(cost);
		return;
	}
	
	dfs(end,pos+1,cost);
	if(cost+price[pos]<=M)
		dfs(end,pos+1,cost+price[pos]);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>price[i];
	}
	
	dfs(N/2,1,0);
	dfs(N,N/2+1,0);
	sort(ansA.begin(),ansA.end());
	for(unsigned int i=0;i<ansB.size();i++){
		ans+=upper_bound(ansA.begin(),ansA.end(),M-ansB[i])-ansA.begin();
	}
	
	cout<<ans<<"\n";

	return 0;
}



