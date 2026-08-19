#include <bits/stdc++.h>
#include <ctime>
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
const int MAXT=10;
int ques[MAXT+2][4];
int T,t;
int num[10],cnt,iget;
bool flag;
//vector<char> memop;
//vector<int> memnum;

void ans(int a,int b,int c,int d){
//	memop.push_back('!');
//	memnum.push_back(a*1000+b*100+c*10+d);
	flag=false;
	if(a!=ques[T][0]) flag=true;
	if(b!=ques[T][1]) flag=true;
	if(c!=ques[T][2]) flag=true;
	if(d!=ques[T][3]) flag=true;
	if(flag){
		cout<<t<<"\n";
		for(int i=1;i<=t;i++){
			cout<<i<<":";
			for(int j=0;j<4;j++) cout<<ques[i][j];
			cout<<"\n";
		}
		
		cout<<"\nFail at "<<T<<":"<<a<<b<<c<<d<<"\n\n";
		
//		for(unsigned int i=0;i<memop.size();i++){
//			cout<<memop[i]<<" "<<memnum[i]<<"\n";
//		}
		system("pause");
	}//else cout<<t-T<<"/"<<t<<" "<<ques[T][0]*1000+ques[T][1]*100+ques[T][2]*10+ques[T][3]<<"="<<a*1000+b*100+c*10+d<<" Passed\n";
	return;
}

int ask(int a,int b,int c,int d){
//	memop.push_back('?');
//	memnum.push_back(a*1000+b*100+c*10+d);
	int re=0;
	if(a==ques[T][0]) re++;
	if(b==ques[T][1]) re++;
	if(c==ques[T][2]) re++;
	if(d==ques[T][3]) re++;
//	memop.push_back('=');
//	memnum.push_back(re);
	return re;
}

void init(){
	int sum=0;cnt=0;
	for(int i=0;i<10;i++) num[i]=0;
	for(int i=0;i<9;i++){
		num[i]=ask(i,i,i,i);		
		sum+=num[i];
		if(num[i]) cnt++;
		if(sum==4) break;
	}
	if(sum<4){
		num[9]=4-sum;
		cnt++;
	}
}

void solve(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	while(T--){
		init();
//		for(int i=0;i<10;i++) cout<<num[i]<<" "; cout<<"\n"<<cnt<<"\n";
		switch(cnt){
			case 1:{
				for(int i=0;i<10;i++)
					if(num[i]) ans(i,i,i,i);
				break;
			}
			case 2:{
				bool flag=false;
				int a=0,b=0,x=0;
				for(int i=0;i<10;i++){
					if(!flag&&num[i]==2) flag=true;
					if(a && num[i]) b=i;
					if(!a && num[i]) a=i;					
					if(!num[i]) x=i;
				}
				if(num[b]>num[a]) swap(a,b);
				
				if(flag){//aabb
					iget=ask(a,a,x,x);
					
					if(iget==2) 	 ans(a,a,b,b);
					else if(iget==0) ans(b,b,a,a);
					else{
						iget=ask(x,a,a,x);
						if(iget==0) 	 ans(a,b,b,a);
						else if(iget==2) ans(b,a,a,b);
						else{
							iget=ask(a,x,a,x);
							if(iget==2) ans(a,b,a,b);
							else 		ans(b,a,b,a);
						}
					}
				}else{//aaab
					iget=ask(b,x,x,x);
					if(iget){ans(b,a,a,a);break;}
					iget=ask(x,b,x,x);
					if(iget){ans(a,b,a,a);break;}
					iget=ask(x,x,b,x);
					if(iget){ans(a,a,b,a);break;}
					else 	 ans(a,a,a,b);
				}
				
				break;
			}
			case 3:{
				int a=0,b=0,c=0,x=0;
				for(int i=0;i<10;i++){
					if(num[i]==2) a=i;
					if(b && num[i]==1) c=i;
					if(!b && num[i]==1) b=i;
					if(!num[i]) x=i;
				}
				
				iget=ask(a,a,x,x);
				if(iget==2){
					iget=ask(a,a,b,c);
					if(iget==4) ans(a,a,b,c);
					else 		ans(a,a,c,b);
				}else if(iget==0){
					iget=ask(b,c,a,a);
					if(iget==4) ans(b,c,a,a);
					else 		ans(c,b,a,a);
				}else{
					iget=ask(b,b,x,x);
					if(iget==1){
						iget=ask(a,b,a,x);
						if(iget==0) 	 ans(b,a,c,a);
						else if(iget==1) ans(b,a,a,c);
						else if(iget==2) ans(a,b,c,a);
						else			 ans(a,b,a,c);
					}else{
						iget=ask(a,x,a,b);
						if(iget==0) 	 ans(c,a,b,a);
						else if(iget==1) ans(a,c,b,a);
						else if(iget==2) ans(c,a,a,b);
						else			 ans(a,c,a,b);
					}
				}				
				break;
			}
			case 4:{
				int a=0,b=0,c=0,d=0,x=0;
				for(int i=0;i<10;i++){
					if(c && num[i]) d=i;
					else if(b && num[i]) c=i;
					else if(a && num[i]) b=i;
					else if(!a && num[i]) a=i;
					if(!num[i]) x=i;
				}
				
				iget=ask(a,a,b,b);
				if(iget==0) swap(a,b);
				if(iget==1){
					iget=ask(a,a,x,x);
					if(iget==0){ swap(a,c); swap(b,d);}
					iget=ask(a,b,c,x);
					
					if(iget==0) 	 ans(b,a,d,c);
					else if(iget==1) ans(b,a,c,d);
					else if(iget==2) ans(a,b,d,c);
					else			 ans(a,b,c,d);
					
					break;
				}
				
				iget=ask(c,c,d,d);
				if(iget==0) swap(c,d);
				
				iget=ask(a,c,b,x);
				if(iget==0) 	 ans(c,a,d,b);
				else if(iget==1) ans(c,a,b,d);
				else if(iget==2) ans(a,c,d,b);
				else			 ans(a,c,b,d);
				
				break;
			}
		}
		
		if(flag) break;
	}

	return;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	mt19937 myrand(time(nullptr));
	
	while(true){
//		memop.clear();
//		memnum.clear();
		t=myrand()%MAXT;
		T=t;
		for(int i=0;i<t;i++){
			int Q=myrand()%10000;
			ques[i][0]=Q%10;
			ques[i][1]=(Q/10)%10;
			ques[i][2]=(Q/100)%10;
			ques[i][3]=Q/1000;
		}
		solve();
		if(flag) break;
	}


	return 0;
}



