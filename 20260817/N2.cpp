#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define Ld long double
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
struct Node{
	lli x;lli y;bool used;
	Node(){x=0;y=0;used=false;}
	Node(lli X,lli Y){x=X;y=Y;used=false;}

	Node operator-(const Node a)const{
		return Node(x-a.x,y-a.y);
	}
	lli operator*(const Node a)const{
		return (x*a.y)-(y*a.x);
	}
	bool operator<(const Node a)const{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
}node[50004]; 
int st[50004],pos; 

lli tris(int a,int b,int c){
	return labs((node[a]-node[c])*(node[b]-node[c]));
}
lli sqrlen(int a,int b){
	return (node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y);
}

int N;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	for(int i=1;i<=N;i++) cin>>node[i].x>>node[i].y;
	
	sort(node+1,node+1+N);
	st[++pos]=1;
	
	for(int i=2;i<=N;i++){
		while(pos>1 && (node[st[pos]]-node[st[pos-1]])*(node[i]-node[st[pos]])<=0 )
			node[st[pos--]].used=false;
		node[i].used=true;
		st[++pos]=i;
	}
	
	int temp=pos;
	for(int i=N;i>=1;i--){
		if(node[i].used) continue;
		while(pos>temp && (node[st[pos]]-node[st[pos-1]])*(node[i]-node[st[pos]])<=0 )
			node[st[pos--]].used=false;
		node[i].used=true;
		st[++pos]=i;
	}
	
	int now=1;lli ans=0;
	for(int i=1;i<=pos;i++){		
		while(tris(st[i],st[i+1],st[(now%pos)+1])>tris(st[i],st[i+1],st[now]))
			now=now%pos+1;
		int temp=now;
		do{
			ans=max(ans,sqrlen(st[i],st[temp]));
			ans=max(ans,sqrlen(st[i+1],st[temp]));
			temp=temp%pos+1;
		} while(tris(st[i],st[i+1],st[temp])==tris(st[i],st[i+1],st[(temp-1==0)?pos:temp-1]) && temp!=now);
		now=temp-1;
	}
	
	cout<<ans<<"\n";

	return 0;
}



