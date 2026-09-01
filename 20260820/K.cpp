#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
//-----------------------------------------
void _QuickStream(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
//------------------------------------------
const Ld PI=acos(-1);
struct Node{
	Ld x;Ld y;
	
	Node(){x=y=0;}
	Node(Ld a,Ld b){x=a,y=b;}
	
	Node operator- (const Node a)const{ return Node(a.x-x,a.y-y); }
	Ld operator* (Node a)const{ return x*a.x+y*a.y;}
}node[4];

Ld length(int a,int b){
	return sqrt((node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y));
}

Ld angle(int a,int b,int c){
	return acos(((node[b]-node[a])*(node[c]-node[a]))/length(a,b)/length(a,c));
}

signed main(){
	_QuickStream();

	for(int i=0;i<4;i++) cin>>node[i].x>>node[i].y;
	Ld sum=0;
	for(int i=0;i<4;i++){
		sum+=angle((i+1)%4,i,(i+2)%4);
//		cout<<angle((i+1)%4,i,(i+2)%4)<<"\n";
	}
	
//	cout<<sum<<"\n";
	if(sum<2*PI) cout<<"No\n";
	else cout<<"Yes\n";
	

	return 0;
}

