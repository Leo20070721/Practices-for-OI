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
const int MAXS=504;
int N,M,R=INT_MAX;;

int amap[MAXS][MAXS];

bool flag;
int deg[MAXS];

stack<int> ans; 
void DFS(int now){	
	for(int i=1;i<=N;i++){
		if(!amap[now][i]) continue;
		amap[now][i]--;
		amap[i][now]--;
		DFS(i);
	}
	ans.push(now);
} 

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>M;
	for(int i=1;i<=M;i++){		
		int f,t;cin>>f>>t;
		N=max(N,f);N=max(N,t);
		R=min(N,f);R=min(N,t);
		amap[f][t]++;
		amap[t][f]++;
		deg[f]++;deg[t]++;
	}
	
	int flag=0,S=INT_MAX;
	for(int i=1;i<=N;i++){
		if(deg[i]%2==0) continue;
		else if(flag==0 || flag==1){
			S=min(S,i);
			if(flag==0) flag=1;
			else        flag=2;
		}
		else{
			cout<<"No\n";
			return 0;
		} 
	}
	
	//cout<<"S:"<<S<<"\n";
	if(S==INT_MAX) DFS(R);
	else DFS(S);
	
	while(!ans.empty()){
		cout<<ans.top()<<"\n";
		ans.pop();
	}

	return 0;
}



