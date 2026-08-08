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
int stat[4][3][2]={
{{ 1,-1},{ 1, 0}, { 0, 1}},
{{-1,-1},{-1, 0}, { 0, 1}},
{{ 1, 1},{ 0,-1}, { 1, 0}},
{{ 1,-1},{ 0, 1}, { 1, 0}} 
};//up,down,right,left | start,mov,nxt | row,column
int T;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>T;
	for(int t=1;t<=T;t++){
		int N;cin>>N;
		string ops;cin>>ops;
		int amap[22][22];memset(amap,0,sizeof(amap));
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				int iget;cin>>iget;
				amap[i][j]=iget;
			}
		}
		
		int op;
		switch(ops[0]){
			case 'u':{op=0;break;}
			case 'd':{op=1;break;}
			case 'r':{op=2;break;}
			case 'l':{op=3;break;}
		}
		
		queue<int> nmap[22];
		for(int i=1;i<=N;i++){
			int temp=-1;
			int posr=(stat[op][0][0]==1?1:N) +stat[op][2][0]*(i-1);
			int posc=(stat[op][0][1]==-1?1:N)+stat[op][2][1]*(i-1);
			if(_TEST>=20)cout<<"start calc at:("<<posr<<","<<posc<<")\n";
			for(int j=1;j<=N;j++){	
				if(_TEST>=25)cout<<"now calc at:("<<posr<<","<<posc<<")="<<amap[posr][posc]<<"\n";
				if(amap[posr][posc]==0){;}
				else if(temp==-1){temp=amap[posr][posc];}
				else if(temp==amap[posr][posc]){
					if(_TEST>=20) cout<<"add,push "<<temp*2<<"\n";
					switch(op){
						case 0: case 1:{nmap[posc].push(temp*2);break;}
						case 2: case 3:{nmap[posr].push(temp*2);break;}
					}
					temp=-1;
				}else{
					if(_TEST>=20) cout<<"chg,push "<<temp<<"\n";
					switch(op){
						case 0: case 1:{nmap[posc].push(temp);break;}
						case 2: case 3:{nmap[posr].push(temp);break;}
					}
					temp=amap[posr][posc];
				}	
				posr+=stat[op][1][0];posc+=stat[op][1][1];	
			}
			if(temp!=-1) {
				switch(op){
					case 0: case 1:{nmap[posc].push(temp);break;}
					case 2: case 3:{nmap[posr].push(temp);break;}
				}
				if(_TEST>=20) cout<<"end,push "<<temp<<"\n";
			}
		}
		
		cout<<"Case #"<<t<<":\n";
		
		int fmap[22][22];memset(fmap,0,sizeof(fmap));
		for(int i=1;i<=N;i++){
			int posr=(stat[op][0][0]==1 ?1:N)+stat[op][2][0]*(i-1);
			int posc=(stat[op][0][1]==-1?1:N)+stat[op][2][1]*(i-1);
			if(_TEST>=20)cout<<"start print at:("<<posr<<","<<posc<<")\n";
			for(int j=1;j<=N;j++){	
				if(op==0 || op==1){					
					if(!nmap[posc].empty()){
						if(_TEST>=20)cout<<"now print at:("<<posr<<","<<posc<<")="<<nmap[posc].front()<<"\n";
						fmap[posr][posc]=nmap[posc].front();
						nmap[posc].pop();
					}else{
						if(_TEST>=20)cout<<"now print at:("<<posr<<","<<posc<<")=0\n";
						fmap[posr][posc]=0;
					}
				}else{					
					if(!nmap[posr].empty()){
						if(_TEST>=20)cout<<"now print at:("<<posr<<","<<posc<<")="<<nmap[posr].front()<<"\n";
						fmap[posr][posc]=nmap[posr].front();
						nmap[posr].pop();
					}else{
						if(_TEST>=20)cout<<"now print at:("<<posr<<","<<posc<<")=0\n";
						fmap[posr][posc]=0;
					}
				}				
				posr+=stat[op][1][0];posc+=stat[op][1][1];	
			}
		}
		
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				cout<<fmap[i][j]<<" ";
			}cout<<"\n";
		}
	}


	return 0;
}



