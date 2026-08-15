#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStreamOpen(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
const bool _QuickStream=true;
//-----------------------------------------
const int half=224;
bool amap[half*2][half*2];int base=half;
int ans[half*2][half*2];
int N,endX,endY;
int op[6][2]={{1,1},{0,1},{-1,1},{1,0},{-1,0},{0,-1}};

queue< pair<int,int> >Q;

signed main(){
	if(_QuickStream) _QuickStreamOpen();
	
	memset(ans,0x3f,sizeof(ans));
	cin>>N>>endX>>endY;
	endX+=base;endY+=base;
	for(int i=1;i<=N;i++){
		int x,y;cin>>x>>y;
		amap[x+base][y+base]=true;
	}
	
	ans[base+0][base+0]=0;
	amap[base+0][base+0]=true;
	Q.push(make_pair(base+0,base+0));
	while(!Q.empty()){
		int nowX=Q.front().first,nowY=Q.front().second;		
		Q.pop();
		for(int i=0;i<6;i++){
			int nxtX=nowX+op[i][0],nxtY=nowY+op[i][1];
			if(amap[nxtX][nxtY]) continue;
			if(nxtX<-201+base || nxtX>201+base ||nxtY<-201+base || nxtY>201+base) continue;
			if(nxtX==endX && nxtY==endY){
				cout<<ans[nowX][nowY]+1<<"\n";
				return 0;
			}
			ans[nxtX][nxtY]=ans[nowX][nowY]+1;
			amap[nxtX][nxtY]=true;
			Q.push(make_pair(nxtX,nxtY));			
		}
	}
	
	cout<<"-1\n";

	return 0;
}

