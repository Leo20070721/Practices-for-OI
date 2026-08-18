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
const lli INF=4e9;
int N;
lli LL[2],LR[2],HL[2],HR[2]; 
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	LL[0]=LL[1]=INF;
	LR[1]=HL[0]=INF;

	cin>>N;
	for(int i=1;i<=N;i++){
		int x,y;cin>>x>>y;
		if(x+y<LL[0]+LL[1]) LL[0]=x,LL[1]=y;
		if(x+y>HR[0]+HR[1]) HR[0]=x,HR[1]=y;
		if(x-y>LR[0]-LR[1]) LR[0]=x,LR[1]=y;
		if(y-x>HL[1]-HL[0]) HL[0]=x,HL[1]=y;
	}
	
//	cout<<"LL:"<<LL[0]<<","<<LL[1]<<"\n";
//	cout<<"HR:"<<HR[0]<<","<<HR[1]<<"\n";
//	cout<<"LR:"<<LR[0]<<","<<LR[1]<<"\n";
//	cout<<"HL:"<<HL[0]<<","<<HL[1]<<"\n";
	
	cout<<max(HR[0]-LL[0]+HR[1]-LL[1],LR[0]-HL[0]+HL[1]-LR[1])<<"\n";

	return 0;
}



