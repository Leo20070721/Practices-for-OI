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
const int MAXN=1e6+12;
int A,B;
int fib[50]={0,1,1};
int f[50]={0,1},b[50]={0,2};

void fibinit(){	
	for(int sec=2;sec<25;sec++){
		fib[2*sec-1]=fib[2*sec-2]+fib[2*sec-3];
		fib[2*sec]=fib[2*sec-1]+fib[2*sec-2];
		f[sec]=f[sec-1]+b[sec-1];
		b[sec]=f[sec-1]+b[sec-1]*2;
	}		
}

int cnt=1;
bool check(int Q,int lst,int sec){
	if(sec==0) return Q==lst;
	
	if(lst==2&&Q>f[sec]+b[sec]){
		cnt+=fib[2*sec]+fib[2*sec-1];
		return check(Q-f[sec]-b[sec],2,sec-1);
	}		
	if(Q>f[sec]){
		cnt+=fib[2*sec-1];
		return check(Q-f[sec],2,sec-1);
	}		
	else 
		return check(Q,1,sec-1);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	fibinit();
	cin>>A>>B;
	if(A>B) swap(A,B); 
	
	if(A==0) cout<<"1\n";
	else if(!check(A,1,24)) cout<<"1\n";
	else{
		if(A+cnt==B) cout<<"0\n";
		else cout<<"1\n";
	}
	
	
	return 0;
}



