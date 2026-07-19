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
const int MAXN=30005;
int T;
struct Root{
	int fa,dis,hav;
	
	Root(){
		fa=0,dis=0,hav=1;
	}
	Root(int gfa,int gdis,int ghav){
		fa=gfa,dis=gdis,hav=ghav;
	}
}root[MAXN];

Root findRoot(int x){
	if(root[x].fa==x) return Root(x,0,root[x].hav);
	Root newRoot=findRoot(root[x].fa) ;
	newRoot.dis+=root[x].dis;
	if(_TEST>=10){
		cout<<"upd x="<<x<<" : fax="<<newRoot.fa<<" dis="<<newRoot.dis<<" faxhav="<<root[newRoot.fa].hav<<"\n"; 
	}
	return root[x]=newRoot;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	for(int i=1;i<MAXN;i++){
		root[i]=Root(i,0,1);
	}

	cin>>T;
	while(T--){
		char cget;cin>>cget;
		int x,y;cin>>x>>y;
		Root rootX,rootY;
		rootX=findRoot(x);rootY=findRoot(y); 
		int fax=rootX.fa,fay=rootY.fa;
		if(_TEST>=10){
			cout<<"x="<<x<<" : fax="<<fax<<" dis="<<root[x].dis<<" faxhav="<<root[fax].hav<<"\n"; 
			cout<<"y="<<y<<" : fay="<<fay<<" dis="<<root[y].dis<<" fayhav="<<root[fay].hav<<"\n";
		}
		
		if(cget == 'M'){
			root[fax]=Root(fay,rootY.hav,rootX.hav);
			root[fay]=Root(fay,0,rootX.hav+rootY.hav);
			if(_TEST>=10){
				cout<<"mov x="<<fax<<" : fax="<<fay<<" dis="<<rootY.hav<<" faxhav="<<rootX.hav+rootY.hav<<"\n"; 
				cout<<"chg y="<<fay<<" : fay="<<fay<<" dis="<<0<<" fayhav="<<rootX.hav+rootY.hav<<"\n"; 
			}
		}else{
			if(fax!=fay){
				cout<<"-1\n";
			}else{
				cout<<abs(root[x].dis-root[y].dis)-1<<"\n";
			}
		}
	}

	return 0;
}



