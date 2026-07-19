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
int A,B,C;
bool flag;
bool vis_static[10];

void dfs(int dep,int temp,bool vis[],int a,int b,int c){
	if(dep==10){
		if(a*B==b*A && a*C==c*A && b*C==c*B){
			flag=true;
			cout<<a<<" "<<b<<" "<<c<<"\n";
		}
		return;
	}
	for(int i=1;i<=9;i++){
		if(vis[i]) continue;
		vis[i] = true;
		
		if(dep%3!=0){
			dfs(dep+1,temp*10+i,vis,a,b,c);
		}else{
			if(dep==3) dfs(dep+1,0,vis,temp*10+i,b,c);
			else if(dep==6) dfs(dep+1,0,vis,a,temp*10+i,c);
			else dfs(dep+1,0,vis,a,b,temp*10+i);
		}
		
		vis[i]=false;
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>A>>B>>C;
	dfs(1,0,vis_static,0,0,0);
	if(!flag) cout<<"No!!!\n";

	return 0;
}



