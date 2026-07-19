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
int cnt=0;
vector<int> ans_out[60000];
void dfs(int lst,int dep,int ans[]){
	for(int i=1;i<=3;i++){
		if(lst-i < 10-dep) break;
		ans[dep-1]=i;
		
		if(dep==10){
			if(lst!=i) continue;
			
			for(int j=0;j<10;j++){
				ans_out[cnt].push_back(ans[j]);
			}
			cnt++;
		}else{
			dfs(lst-i,dep+1,ans);
		}		
	}
	return;
}

int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	int ans[10];
	if(N<10 || N>30){
		cout<<"0";
		return 0;
	}
	dfs(N,1,ans);
	cout<<cnt<<"\n";
	for(int i=0;i<cnt;i++){
		for(int j=0;j<10;j++){
			cout<<ans_out[i][j]<<" ";
		}cout<<"\n";
	}

	return 0;
}



