#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
const int MAXN=1e5+12;
int N,M,F[MAXN],S[MAXN],ans=2e9;
deque< pair<int,int> > mins;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>F[i]>>S[i];
	
	int L=1,R=1,nowf=0;
	for(;R<=N;R++){
		nowf+=F[R];
		while(!mins.empty()&&mins.back().second<S[R]) mins.pop_back();
		mins.push_back(make_pair(R,S[R]));
		if(nowf>=M) break;
	}
	while(R<=N){		
		if(nowf>=M) {
//			cout<<L<<"->"<<R<<":"<<nowf<<","<<mins.front().second<<"\n";
			ans=min(ans,mins.front().second);
			nowf-=F[L];
			L++;
			while(!mins.empty() && mins.front().first<L)
				mins.pop_front();
		}
		else {
			R++;
			nowf+=F[R];
			while(!mins.empty() && mins.back().second<S[R])
				mins.pop_back();
			mins.push_back(make_pair(R,S[R]));			
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}



