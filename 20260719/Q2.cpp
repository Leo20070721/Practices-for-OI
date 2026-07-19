#include <bits/stdc++.h>
using namespace std;
#define MAXS 100005 
#define lli long long int

int N,Q,M;

lli line[MAXS];
//----------------------------------------------------
lli xd_tree[MAXS<<2];
lli xd_add_tag[MAXS<<2]; 
lli xd_mult_tag[MAXS<<2]; 

inline int ls(int fa) {return fa<<1;}
inline int rs(int fa) {return fa<<1|1;}
//inline int fa(int son) {return son>>1;}
inline void pull_up_sum(int fa)
{
	xd_tree[fa] = xd_tree[ls(fa)] + xd_tree[rs(fa)] ;
//	cout<<"Pull_up: "<<fa<<" <-"<<xd_tree[fa]<<"- "<<ls(fa)<<" "<<rs(fa)<<"\n";
}

void build(int p,int l,int r)
{
	xd_add_tag[p]=0;
	xd_mult_tag[p]=1;
	if(l == r) {xd_tree[p] = line[l]; return;}
	
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	
	pull_up_sum(p);
}
//-----------------------------------------------------
//xd_tree
inline void xd_add(int p,int l,int r,lli num)
{
	xd_add_tag[p]=(xd_add_tag[p]+num)%M;
	xd_tree[p]=(xd_tree[p]+num*(r-l+1))%M;
}
inline void xd_mult(int p,int l,int r,lli num)
{
	xd_mult_tag[p]=(xd_mult_tag[p]*num)%M; 
	xd_add_tag[p]=(xd_add_tag[p]*num)%M;
	xd_tree[p]=(xd_tree[p]*num)%M;
}

inline void push_down(int p,int l,int r)
{
//	cout<<"Push_down:"<<p<<"["<<l<<","<<r<<"] -"<<xd_add_tag[p]<<"-> "<<ls(p)<<" "<<rs(p)<<"\n";
	int mid=(l+r)>>1;
	
	xd_mult(ls(p),l  ,mid,xd_mult_tag[p]);
	xd_mult(rs(p),mid+1,r,xd_mult_tag[p]);
	
	xd_add(ls(p),l,mid,xd_add_tag[p]);
	xd_add(rs(p),mid+1,r,xd_add_tag[p]);
	
	xd_add_tag[p]=0;xd_mult_tag[p]=1;
}

inline void update_add(int cl,int cr,lli num,int p,int l,int r)
{
	if(cl<=l && r<=cr)
	{
		xd_tree[p]=(xd_tree[p]+num*(r-l+1))%M;
		xd_add_tag[p]=(xd_add_tag[p]+num)%M;
		return;
	}
	
	push_down(p,l,r);
	
	int mid=(l+r)>>1;
	if(cl<=mid) update_add(cl,cr,num,ls(p),l,mid);
	if(cr> mid) update_add(cl,cr,num,rs(p),mid+1,r);
	
	pull_up_sum(p);
}

inline void update_mult(int cl,int cr,lli num,int p,int l,int r)
{
	if(cl<=l && r<=cr)
	{
		xd_tree[p]=(xd_tree[p]*num)%M;
		xd_add_tag[p]=(xd_add_tag[p]*num)%M;
		xd_mult_tag[p]=(xd_mult_tag[p]*num)%M;
		return;
	}
	
	push_down(p,l,r);
	
	int mid=(l+r)>>1;
	if(cl<=mid) update_mult(cl,cr,num,ls(p),l,mid);
	if(cr> mid) update_mult(cl,cr,num,rs(p),mid+1,r);
	
	pull_up_sum(p);
}
//------------------------------------------------------
lli sum_ask(int ql,int qr,int p,int l,int r)
{
	
	if(ql <= l && r <= qr) 
	{
//		cout<<p<<"["<<l<<","<<r<<"] :"<<xd_tree[p]<<" "<<xd_add_tag[p]<<" "<<xd_tree[p]<<"\n";
		return xd_tree[p];
	}
	
	lli re=0;
	int mid=(l+r)>>1;
	
	push_down(p,l,r);

	if(ql<=mid) re+=sum_ask(ql,qr,ls(p),l,mid);
	re%=M;
	if(qr> mid) re+=sum_ask(ql,qr,rs(p),mid+1,r);
	re%=M;
//	cout<<p<<"["<<l<<","<<r<<"] :"<<xd_tree[p]<<" "<<xd_add_tag[p]<<" "<<re<<"\n"; 
	return re;
}
//------------------------------------------------------

int main()
{
	cin>>N>>Q>>M;
	for(int I=1;I<=N;I++)
	{cin>>line[I];}
	
	build(1,1,N);
	
	for(int I=1;I<=Q;I++)
	{
		int flag,l,r,num;
		cin>>flag;
		if(flag==2)
		{
			cin>>l>>r>>num;
			update_add(l,r,num,1,1,N);
		}
		else if(flag==3)
		{
			cin>>l>>r;
			cout<<(sum_ask(l,r,1,1,N))%M<<"\n";
		}
		else if(flag==1)
		{
			cin>>l>>r>>num;
			update_mult(l,r,num,1,1,N);
		}
	}
	
}
