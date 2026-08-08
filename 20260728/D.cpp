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
const int MAXS=1e6+24;
int N,H[MAXS];
lli V[MAXS],val[MAXS],ans;
stack < pair<int,int> > Q1,Q2;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>H[i]>>V[i];
	
	for(int i=1;i<=N;i++){		
		while(!Q1.empty() && H[i]>Q1.top().second) Q1.pop();
		if(!Q1.empty()){
			val[Q1.top().first]+=V[i];
			ans=max(ans,val[Q1.top().first]);
		}		
		Q1.push(make_pair(i,H[i]));
	}
	for(int i=N;i>=1;i--){
		while(!Q2.empty() && H[i]>Q2.top().second) Q2.pop();
		if(!Q2.empty()){
			val[Q2.top().first]+=V[i];
			ans=max(ans,val[Q2.top().first]);
		}		
		Q2.push(make_pair(i,H[i]));
	}

	cout<<ans<<"\n";

	return 0;
}



