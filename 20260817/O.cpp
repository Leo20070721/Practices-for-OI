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
struct Node{
	Ld x;Ld y;bool used;
	Node(){x=0;y=0;used=false;}
	Node(Ld X,Ld Y){x=X;y=Y;used=false;}

	Node operator-(const Node a)const{
		return Node(x-a.x,y-a.y);
	}
	Ld operator*(const Node a)const{
		return (x*a.y)-(y*a.x);
	}
	bool operator<(const Node a)const{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
}node[50004]; 
int st[50004],pos; 

Ld length(int a,int b){
	return sqrt((node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y));
}

int N;
Ld A,B,R,ans;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N;
	cin>>A>>B>>R;
	A-=2*R,B-=2*R;
	Ld l=sqrt(A*A+B*B)/2,alpha=atan(A/B);
	for(int i=1;i<=N;i++){
		Ld x,y,theta;cin>>x>>y>>theta;
		node[4*i-3].x=x+l*cos(theta+alpha);node[4*i-3].y=y+l*sin(theta+alpha);
		node[4*i-2].x=x+l*cos(theta-alpha);node[4*i-2].y=y+l*sin(theta-alpha);
		node[4*i-1].x=x+l*cos(theta+acos(-1)+alpha);node[4*i-1].y=y+l*sin(theta+acos(-1)+alpha);
		node[4*i  ].x=x+l*cos(theta+acos(-1)-alpha);node[4*i  ].y=y+l*sin(theta+acos(-1)-alpha);
	}
//	for(int i=1;i<=4*N;i++)
//		cout<<i<<":"<<node[i].x<<" "<<node[i].y<<"\n";
//		cout<<"\n";
	
	sort(node+1,node+1+4*N);
	st[++pos]=1;
	
	for(int i=2;i<=4*N;i++){
		while(pos>1 && (node[st[pos]]-node[st[pos-1]])*(node[i]-node[st[pos]])<=0 )
			node[st[pos--]].used=false;
		node[i].used=true;
		st[++pos]=i;
	}
	
	int temp=pos;
	for(int i=4*N;i>=1;i--){
		if(node[i].used) continue;
		while(pos>temp && (node[st[pos]]-node[st[pos-1]])*(node[i]-node[st[pos]])<=0 )
			node[st[pos--]].used=false;
		node[i].used=true;
		st[++pos]=i;
	}
	
	for(int i=1;i<pos;i++){
		ans+=length(st[i],st[i+1]);
	}
	ans+=length(st[1],st[pos]);
	printf("%.2Lf\n",ans+2*acos(-1)*R);//

	return 0;
}



