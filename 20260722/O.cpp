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
int M,S,C,ans,used=1,hall[205];
priority_queue<int,vector<int>,greater<int> > space;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>M>>S>>C;
	for(int i=1;i<=C;i++) cin>>hall[i];
	sort(hall+1,hall+1+C);
	
	int temp,ans=C,iget;
	for(int i=1;i<=C;i++){
		iget=hall[i];		
		if(i!=1){
			if(iget-temp-1>0){
				space.push(iget-temp-1);
				used++;
			}
		}		
		temp=iget;
	}
	
	for(int i=0;i<used-M;i++){
		ans+=space.top();
		space.pop();
	}
	
	cout<<ans<<"\n";
	return 0;
}



