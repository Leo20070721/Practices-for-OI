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
int N;
stack < pair<int,int> > Q;
int ans[3000005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++){
		int iget;cin>>iget;
		while(!Q.empty() && iget>Q.top().second){
			ans[Q.top().first]=i;
			Q.pop();
		}
		Q.push(make_pair(i,iget));		
	}
	
	while(!Q.empty()){
		ans[Q.top().first]=0;
		Q.pop();
	}
	
	for(int i=1;i<=N;i++){
		cout<<ans[i]<<" ";
	}cout<<"\n";

	return 0;
}



