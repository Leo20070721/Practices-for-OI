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
deque < pair<int,lli> > maxn,minn;
vector <lli> ans_min,ans_max;
int N,K;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		lli a;cin>>a;
		
		if(maxn.size()>0 && maxn.front().first <= i-K) maxn.pop_front();
		if(minn.size()>0 && minn.front().first <= i-K) minn.pop_front();
		
		while(maxn.size()>0 && a>maxn.back().second) maxn.pop_back();
		maxn.push_back(make_pair(i,a));
		while(minn.size()>0 && a<minn.back().second) minn.pop_back();
		minn.push_back(make_pair(i,a));
		
		if(i<K) continue;
		ans_min.push_back(minn.front().second);
		ans_max.push_back(maxn.front().second);
		//cout<<minn.front().second<<"\n"<<maxn.front().second<<"\n\n";
	}

	for(unsigned int i=0;i<ans_min.size();i++){
		cout<<ans_min[i]<<" ";
	}cout<<"\n";
	for(unsigned int i=0;i<ans_max.size();i++){
		cout<<ans_max[i]<<" ";
	}cout<<"\n";

	return 0;
}



