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
int amap[5][5];
bool vis[5][5];
vector< pair<int,int> > pos[3];
int ans=INT_MAX;

void DFS(int deep,int x,int y,int re){
	if(vis[x][y]) return;
	re=re*10+amap[x][y];
	if(deep==3){
		ans=min(ans,re);
		return;
	}
	vis[x][y]=true;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			DFS(deep+1,x+i,y+j,re);
		}
	}
	vis[x][y]=false;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i==0 || j==0 || i==4 || j==4) vis[i][j]=true;
		}
	}
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			char cget;cin>>cget;
			amap[i][j]=cget-'A'+1;
			pos[cget-'A'].push_back(make_pair(i,j));
		}
	}
	
	int bgn=0;while(pos[bgn].size()==0)bgn++;
	
	for(unsigned int i=0;i<pos[bgn].size();i++){
		pair<int,int> now=pos[bgn][i];
		int x=now.first,y=now.second;
		DFS(1,x,y,0);
	} 
	
	for(int i=100;i>0;i/=10){
		cout<<char(((ans/i)%10)+'A'-1);
	}cout<<"\n";

	return 0;
}



