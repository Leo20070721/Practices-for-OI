#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define int long long
//-----------------------------------------
void _QuickStream(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
//------------------------------------------
int N,M,Q;
int Ax[200005],Ay[200005];
struct mov{
	int rot;//1c -1cc
	bool xy;//Fx Ty
	int pos;
	
	mov(){rot=0;xy=false;pos=0;}
	mov(int a){rot=a;xy=false;pos=0;}
	mov(bool a,int b){rot=0;xy=a;pos=b;}
};
mov OP[200005];

struct Ques{
	int quest;int opt;int who;
	int x;int y;
};
Ques ques[200005];
bool cmp1(Ques& a,Ques& b){return a.opt<b.opt;}
bool cmp2(Ques& a,Ques& b){return a.quest<b.quest;}

signed main(){
	_QuickStream();
	
	cin>>N;
	for(int i=1;i<=N;i++) cin>>Ax[i]>>Ay[i];

	cin>>M;
	for(int i=1;i<=M;i++){
		int op;cin>>op;
		if(op==1) OP[i].rot=1;
		else if(op==2) OP[i].rot=-1;
		else{
			int p;cin>>p;
			if(op==3) OP[i].xy=false,OP[i].pos=p;
			else OP[i].xy=true,OP[i].pos=p;
		}
	}
	
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>ques[i].opt>>ques[i].who;
		ques[i].quest=i;
	}
	
	sort(ques+1,ques+1+Q,cmp1);
	
	
	int North=0;//x÷·’˝œÚ
	int movx=0,movy=0; bool negx=false,negy=false;
	int T=1;
	for(int i=1;i<=Q;i++){
		while(T<=ques[i].opt){
			if(OP[T].rot==1){
				North=(North-1+4)%4;
			}else if(OP[T].rot==-1){
				North=(North+1)%4;
			}else if(OP[T].xy==false){
				if		(North==0){movx=2*OP[T].pos-movx; negx=!negx;}
				else if (North==1){movy=-2*OP[T].pos-movy; negy=!negy;}
				else if (North==2){movx=-2*OP[T].pos-movx; negx=!negx;}
				else			  {movy=2*OP[T].pos-movy; negy=!negy;}
			}else{
				if		(North==0){movy=2*OP[T].pos-movy; negy=!negy;}
				else if (North==1){movx=2*OP[T].pos-movx; negx=!negx;}
				else if (North==2){movy=-2*OP[T].pos-movy; negy=!negy;}
				else			  {movx=-2*OP[T].pos-movx; negx=!negx;}
			}
			T++;
		}
		int nowx=Ax[ques[i].who],nowy=Ay[ques[i].who];
		nowx=movx+(negx?-1:1)*nowx;
		nowy=movy+(negy?-1:1)*nowy;
		
		int nowt=nowx;
		if(North==0){;}
		else if(North==1){nowx=-nowy,nowy=nowt;}
		else if(North==2){nowx=-nowx,nowy=-nowy;}
		else {nowx=nowy,nowy=-nowt;}
		
		ques[i].x=nowx;ques[i].y=nowy;
	}
	
	sort(ques+1,ques+1+Q,cmp2);
	for(int i=1;i<=Q;i++){
		cout<<ques[i].x<<" "<<ques[i].y<<"\n";
	}

	return 0;
}

