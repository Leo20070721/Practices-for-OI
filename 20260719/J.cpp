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
struct PairHeap{
	bool deleted;
	int val;
	int pos;
	PairHeap* fa;
	PairHeap* root;
	PairHeap* child;
	PairHeap* nxt;
	
	PairHeap(){
		deleted=false;
		val=0;
		pos=0;
		fa=this;
		root=this;
		child=nullptr;
		nxt=nullptr;
	}
};

PairHeap* findRoot(PairHeap* a){
	if(a->fa==a) return a;
	if(!a->root->deleted){
		if(a->root==a) return a->root;
		return a->root=findRoot(a->root);
	}
	return a->root=findRoot(a->fa);
}

int query(PairHeap* a){
	return a->val;	
}
	
PairHeap* meld(PairHeap* a,PairHeap* b){
	if(a == nullptr) return b;
	if(b == nullptr) return a;
	
	if(a->val > b->val) swap(a,b);
	if(a->val == b->val && a->pos > b->pos) swap(a,b);
	b->nxt=a->child;
	a->child=b;
	b->fa=a;
	b->root=a;
	return a;
}
	
PairHeap* insert(PairHeap* a,int num){
	PairHeap* b=new PairHeap;
	b->val=num;
	return meld(a,b);
}

PairHeap* merge(PairHeap* a){
	if(a==nullptr || a->nxt==nullptr) return a;
	PairHeap* b=a->nxt;
	PairHeap* x=b->nxt;
	a->nxt=b->nxt=nullptr;
	return meld(merge(x),meld(a,b));
}

PairHeap* deleteRoot(PairHeap* a){
	PairHeap* re=merge(a->child);
	if(re!=nullptr){
		re->fa=re;
		re->root=re;
		a->child=re;
	}
	a->deleted=true;
	//delete a;
	return re;
}
//-------------------------------------------------
int N,M;
PairHeap P[100005];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>P[i].val;
	for(int i=1;i<=N;i++) P[i].pos=i;
	
	while(M--){
		int opget;cin>>opget;
		if(opget==1){
			int x,y;cin>>x>>y;
			if(P[x].deleted) {
				if(_TEST>=10) cout<<"P[x="<<x<<"] had been deleted.\n";
				continue;
			}
			if(P[y].deleted){
				if(_TEST>=10) cout<<"P[y="<<y<<"] had been deleted.\n";
				continue;
			}
			PairHeap* fax=findRoot(P+x);
			PairHeap* fay=findRoot(P+y);
			if(fax!=fay){
				if(_TEST>=10) cout<<"meld:faxval="<<fax->val<<" fayval="<<fay->val<<"\n";
				meld(fax,fay);
			}else{
				if(_TEST>=10) cout<<"x="<<x<<" & y="<<y<<"have been in the same heap.\n";
			}
		}else{
			int x;cin>>x;
			if(P[x].deleted){
				if(_TEST>=10) cout<<"P["<<x<<"] had been deleted.\n";
				cout<<"-1\n";
				continue;
			}else{
				PairHeap* fa=findRoot(P+x);
				if(_TEST>=10) cout<<"delete:val="<<fa->val<<"\n";
				cout<<fa->val<<"\n";
				deleteRoot(fa);
			}
		}
	}

	return 0;
}



