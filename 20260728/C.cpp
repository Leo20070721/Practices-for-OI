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
lli ans;
int N,H[80005];
stack< pair<int,int> >Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>H[i];
	
	for(int i=N;i>=1;i--){
		while(!Q.empty()){
			if(H[i]>Q.top().second) Q.pop();
			else break;
		}
		
		if(Q.empty()) ans+=N-i;
		else ans+=Q.top().first-i-1;
		
		Q.push(make_pair(i,H[i]));
	}
	
	cout<<ans<<"\n";

	return 0;
}



