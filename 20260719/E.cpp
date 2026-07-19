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
		set <lli> vis;
		vector<lli> ans;
		int N;cin>>N;
		while(N--){
			lli lliget;cin>>lliget;
			if(vis.find(lliget)==vis.end()){
				vis.insert(lliget);
				ans.push_back(lliget);
			}
		}
		for(unsigned int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}

	return 0;
}



