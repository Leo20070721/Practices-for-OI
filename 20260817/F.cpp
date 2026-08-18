#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
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
struct Node{
	int x;int y;bool type;bool used;
	Node(){x=0;y=0;type=false;used=false;}
	Node(int X,int Y){x=X;y=Y;type=false;used=false;}

	Node operator-(const Node a)const{
		return Node(x-a.x,y-a.y);
	}
	int operator*(const Node a)const{
		return (x*a.y)-(y*a.x);
	}
	bool operator<(const Node a)const{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
}node[200005]; 
int st[200005],pos; 

int N,M;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>node[i].x>>node[i].y;
	cin>>M;
	for(int i=N+1;i<=N+M;i++){
		cin>>node[i].x>>node[i].y;
		node[i].type=true;
	}
	
	sort(node+1,node+1+N+M);
	st[++pos]=1;
	
	for(int i=2;i<=N+M;i++){
		while(pos>1 && (node[st[pos]]-node[st[pos-1]])*(node[i]-node[st[pos]])<0 )
			node[st[pos--]].used=false;
		node[i].used=true;
		st[++pos]=i;
	}
	
	int temp=pos;
	for(int i=N+M;i>=1;i--){
		if(node[i].used) continue;
		while(pos>temp && (node[st[pos]]-node[st[pos-1]])*(node[i]-node[st[pos]])<0 )
			node[st[pos--]].used=false;
		node[i].used=true;
		st[++pos]=i;
	}
	
	for(int i=1;i<=pos;i++){
		if(node[st[i]].type){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";

	return 0;
}
