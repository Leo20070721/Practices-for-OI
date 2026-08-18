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
int N,buck[55],ans;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	int T;cin>>T;
	while(T--){
		cin>>N;
		ans=0;
		for(int i=1;i<=N;i++) buck[i]=0;
		for(int i=1;i<=N;i++){
			int iget;cin>>iget;
			buck[iget]++;
		}
		
		for(int i=-N+1;i<N;i++){
			int nans=0;
			for(int j=max(1,i+1);2*j<=N+i+1;j++){
				if(j==N+1+i-j) nans+=buck[j]/2;
				else nans+=min(buck[j],buck[N+1+i-j]);
			}
			ans=max(ans,nans);
		}
		cout<<ans<<"\n";
	}

	return 0;
}



