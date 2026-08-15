#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
const bool _QuickStream=true;
//-----------------------------------------
const int MAXN=100;
int N,M,ans;
int amap[MAXN][MAXN];
bool vis[MAXN][MAXN];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void init(){
	N=M=ans=0;
	memset(vis,0,sizeof(vis));
}

bool isLegal(int x,int y){
	return ( x>0 && y>0 && x<=N && y<=M);
}

struct Node{
	int x;int y;
	Node(){x=0;y=0;}
	Node(int a,int b){x=a;y=b;}
};

queue<Node> Q;
int re[2];
int BFS(int bgnX,int bgnY){
	while(!Q.empty()) Q.pop();
	re[0]=re[1]=0;
	Q.push(Node(bgnX,bgnY));
	while(!Q.empty()){
		int nowX,nowY;
		nowX=Q.front().x;
		nowY=Q.front().y;
		Q.pop();
		if(vis[nowX][nowY]) continue;		
		vis[nowX][nowY]=true;
		
		re[(nowX+nowY)%2]++;		
		for(int k=0;k<4;k++){
			int nxtX=nowX+mv[k][0],nxtY=nowY+mv[k][1];
			if(!isLegal(nxtX,nxtY)) continue;
			if(!(amap[nxtX][nxtY]==0)) continue;
			if(vis[nxtX][nxtY]) continue;
			
			Q.push(Node(nxtX,nxtY));
		} 
	}
	return max(re[0],re[1]);
}

signed main(){
	if(_QuickStream) _QuickStreamOpen();
	init();

	cin>>N>>M;
	for(int i=1;i<=N;i++){
		string sget;cin>>sget;
		for(int j=1;j<=M;j++){
			amap[i][j]=sget[j-1]-'0';
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(amap[i][j]==2){
				ans++;
				for(int k=0;k<4;k++){
					int _i=i+mv[k][0],_j=j+mv[k][1];
					if(!isLegal(_i,_j)) continue;
					if(amap[_i][_j]==0) amap[_i][_j]=1;
				}
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(vis[i][j]) continue;
			if(amap[i][j]!=0) continue;
//			cout<<"get ans from "<<i<<","<<j<<":"<<nans<<"\n";
			ans+=BFS(i,j);
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}

