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
int W,N,val[30005],ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>W>>N;
	for(int i=1;i<=N;i++) cin>>val[i];
	sort(val+1,val+1+N);
	int l=1,r=N;
	while(l<=r){		
		if(val[l]+val[r]<=W) l++;
		r--;ans++; 
	}
	
	cout<<ans<<"\n";
	return 0;
}



