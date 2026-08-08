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
const int MAXS=3e6+24;
int N,a[MAXS],ans[MAXS]; 
stack< pair<int,int> > Q;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=N;i>=1;i--){
		while(!Q.empty()){
			if(a[i]>=Q.top().second) Q.pop();
			else break;
		}
		
		if(!Q.empty()) ans[i]=Q.top().first;
		Q.push(make_pair(i,a[i]));
	}
	
	for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
	cout<<"\n";	

	return 0;
}



