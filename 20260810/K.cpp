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
const bool _QuickStream=false;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
const Ld INF=1e9;
int N;
bool amap[155][155];
int X[155],Y[155];

Ld Euler(int a,int b){
	Ld x1=X[a],x2=X[b],y1=Y[a],y2=Y[b];
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

Ld mp[155][155];
Ld maxmp[155];

bool vis[155];
vector<int> region[155];int cnt;
Ld rlen[155];
void DFS(int pos){
	vis[pos]=true;region[cnt].push_back(pos);
	rlen[cnt]=max(rlen[cnt],maxmp[pos]);
	for(int i=1;i<=N;i++){
		if(amap[pos][i] && !vis[i]) DFS(i); 
	}
}


signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	//读入 
	cin>>N;
	for(int i=1;i<=N;i++) cin>>X[i]>>Y[i];
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		for(int j=1;j<=N;j++){
			amap[i][j]=(sget[j-1]-'0');
			if(i==j) mp[i][j]=0;
			else if(amap[i][j]) mp[i][j]=Euler(i,j);
			else mp[i][j]=INF;
		}
	}
	//预处理最短路 
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
//	for(int i=1;i<=N;i++){
//		for(int j=1;j<=N;j++){
//			if(mp[i][j]==INF) cout<<"0\t";
//			else cout<<mp[i][j]<<"\t";
//		}cout<<"\n";	
//	}
	//寻找最长最短路
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(mp[i][j]==INF) continue;
			maxmp[i]=max(maxmp[i],mp[i][j]);
		}
	}
//	for(int i=1;i<=N;i++) cout<<maxmp[i]<<"\n";
	//分区
	for(int i=1;i<=N;i++){
		if(!vis[i]){
			cnt++;
			DFS(i);	
		}
	}
			
	Ld ans=INF;
	for(int i=1;i<cnt;i++){
	for(int j=i+1;j<=cnt;j++){
	for(unsigned int _i=0;_i<region[i].size();_i++){
	for(unsigned int _j=0;_j<region[j].size();_j++){
		int a=region[i][_i],b=region[j][_j];
		Ld nans=max(max(rlen[i],rlen[j]),maxmp[a]+maxmp[b]+Euler(a,b));
		ans=min(ans,nans);
	}}}}
	
	printf("%.6Lf\n",ans);

	return 0;
}



