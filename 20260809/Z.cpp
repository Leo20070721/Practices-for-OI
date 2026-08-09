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
const int MAXS=2e5+24;
int N,M;

vector<int> amap[MAXS];
unsigned int pos[MAXS];

bool flag;
int in[MAXS],out[MAXS];

stack<int> ans; 
void DFS(int now){	
	for(unsigned int i=pos[now];i<amap[now].size();i=pos[now]){
		int nxt=amap[now][pos[now]];
		pos[now]++;
		DFS(nxt);		
	}
	ans.push(now);
} 

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>M;
	for(int i=1;i<=M;i++){
		int f,t;cin>>f>>t;
		amap[f].push_back(t);
		out[f]++;in[t]++;
	}
	
	int flag=0,S=-1;
	for(int i=1;i<=N;i++){
		sort(amap[i].begin(),amap[i].end());
		if(in[i]==out[i]) continue;
		else if(in[i]==out[i]+1 && (flag==0 || flag==-1)){
			if(flag==0) flag=1;
			else        flag=-2;
		}
		else if(in[i]+1==out[i] && (flag==0 || flag==1)){
			S=i;
			if(flag==0) flag=-1;
			else        flag=2;
		}
		else{
			cout<<"No\n";
			return 0;
		} 
	}
	
	//cout<<"S:"<<S<<"\n";
	if(S==-1) DFS(1);
	else DFS(S);
	
	while(!ans.empty()){
		cout<<ans.top()<<" ";
		ans.pop();
	}cout<<"\n";

	return 0;
}



