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
int T;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		int N;cin>>N;
		int num=0,ans=0;bool flag=true;
		for(int i=1;i<=N;i++){
			int iget;cin>>iget;
			if(iget>0) num++;
			if(iget>1) flag=false;
			ans^=iget;
		}
		
		if(flag){
			if(num%2) cout<<"Brother\n";
			else cout<<"John\n";
		}else{
			if(num && ans==0) cout<<"Brother\n";
			else cout<<"John\n";
		}
	} 

	return 0;
}



