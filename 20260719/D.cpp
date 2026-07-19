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
lli P,sum[500005],ans;
deque < pair<int,lli> > sum_min;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>P;
		sum[i]=sum[i-1]+P;
	}
	
	ans=INT_MIN;
	sum_min.push_back(make_pair(0,0));
	for(int i=1;i<=N;i++){
		if(sum_min.front().first<i-M) sum_min.pop_front();
		ans=max(ans,sum[i]-sum_min.front().second);
		while(sum_min.size()>0 && sum[i]<sum_min.back().second) sum_min.pop_back();
		sum_min.push_back(make_pair(i,sum[i]));		
	} 
	
	cout<<ans<<"\n";

	return 0;
}



