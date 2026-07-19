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
struct Node{
	lli val;
	lli lazyTag;
	lli L,R,len;
	
	Node(){
		val=0;
		lazyTag=0;
		L=R=0;
	}
}SegmentTree[400005];
lli val[100005];

lli create(lli root,lli L,lli R){
	SegmentTree[root].len=R-L+1;
	if(R-L>0){
		lli sum=0;
		
		SegmentTree[root].L=L;
		SegmentTree[root].R=R;
		lli mid=(R+L)>>1;
		if(L<=mid) sum+=create(root*2,L,mid);
		if(R> mid) sum+=create(root*2+1,mid+1,R);
		if(_TEST>=20)cout<<"Create: Node "<<root<<" L="<<L<<" R="<<R<<" val="<<sum<<"\n";
		return SegmentTree[root].val=sum;
	}else{
		if(_TEST>=20)cout<<"Create: Leaf "<<root<<" pos="<<R<<" val="<<val[R]<<"\n";
		SegmentTree[root].L=SegmentTree[root].R=R;
		return SegmentTree[root].val=val[R];
	}
}

void add(int root,lli L,lli R,lli num){
	if(SegmentTree[root].L>=L && SegmentTree[root].R<=R){		
		SegmentTree[root].lazyTag+=num;		
	}else{
		lli mid=(SegmentTree[root].R+SegmentTree[root].L)>>1;
		if(L<=mid) add(root*2,L,R,num);
		if(R> mid) add(root*2+1,L,R,num);
		SegmentTree[root].val+=num*(min(R,SegmentTree[root].R)-max(L,SegmentTree[root].L)+1);
	}
}

void pushDown(lli root){
	SegmentTree[root*2].lazyTag+=SegmentTree[root].lazyTag;
	SegmentTree[root*2+1].lazyTag+=SegmentTree[root].lazyTag;
	SegmentTree[root].val+=SegmentTree[root].lazyTag*SegmentTree[root].len;
	SegmentTree[root].lazyTag=0;
}

lli query(lli root,lli L,lli R){
	if(SegmentTree[root].L>=L && SegmentTree[root].R<=R){
		if(_TEST>=10) cout<<"Query get: "<<SegmentTree[root].L<<"->"<<SegmentTree[root].R<<" val="<<SegmentTree[root].val+SegmentTree[root].lazyTag*SegmentTree[root].len<<"\n";
		return SegmentTree[root].val+SegmentTree[root].lazyTag*SegmentTree[root].len;
	}else{
		lli sum=0;
		if(SegmentTree[root].lazyTag!=0) pushDown(root);
		
		lli mid=(SegmentTree[root].R+SegmentTree[root].L)>>1;
		if(L<=mid) sum+=query(root*2,L,R);
		if(R> mid) sum+=query(root*2+1,L,R);
		if(_TEST>=10) cout<<"Query cal: "<<max(L,SegmentTree[root].L)<<"->"<<min(R,SegmentTree[root].R)<<" val="<<sum<<" from "<<SegmentTree[root].L<<"->"<<SegmentTree[root].R<<"\n";
		return sum;
	}
}

void check(lli root,lli L,lli R){
	if(SegmentTree[root].R==SegmentTree[root].L){
		cout<<"Leaf:"<<root<<" pos="<<SegmentTree[root].R<<" val="<<SegmentTree[root].val<<" LazyTag="<<SegmentTree[root].lazyTag<<"\n";
	}else{
		lli mid=(SegmentTree[root].L+SegmentTree[root].R)>>1;
		cout<<"Node:"<<root<<" pos="<<SegmentTree[root].L<<"->"<<SegmentTree[root].R<<" val="<<SegmentTree[root].val<<" LazyTag="<<SegmentTree[root].lazyTag<<"\n";
		if(L<=mid) check(root*2,L,R);
		if(R> mid) check(root*2+1,L,R);
	}
}

//------------------------------------------
lli N,M;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>M;
	for(lli i=1;i<=N;i++) cin>>val[i];
	create(1,1,N);
	if(_TEST>=20)check(1,1,N);
	
	for(lli i=1;i<=M;i++){
		int op;cin>>op;
		if(op==1){
			lli x,y,k;cin>>x>>y>>k;
			add(1,x,y,k);
		}else{
			lli x,y;cin>>x>>y;
			cout<<query(1,x,y)<<"\n";
		}
		
		if(_TEST>=20)check(1,1,N);
	}

	return 0;
}



