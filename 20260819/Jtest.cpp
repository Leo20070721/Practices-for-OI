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
lli X[MAXT+2],N[MAXT+2];
int T,t;
bool flag;
//vector<char> memop;
//vector<int> memnum;

int ans(){
//	memop.push_back('!');
//	memnum.push_back(a*1000+b*100+c*10+d);
	flag=false;
	if(X[T]!=N[T]) flag=true;
	if(flag){
		cout<<t<<"\n";
		for(int i=0;i<t;i++){
			if(N[i]!=X[i]) cout<<"Fail at ";
			cout<<i<<":"<<N[i]<<" "<<X[i]<<"\n";
		}
		
//		for(unsigned int i=0;i<memop.size();i++){
//			cout<<memop[i]<<" "<<memnum[i]<<"\n";
//		}
		system("pause");
		return -1;
	}//else cout<<t-T<<"/"<<t<<" "<<ques[T][0]*1000+ques[T][1]*100+ques[T][2]*10+ques[T][3]<<"="<<a*1000+b*100+c*10+d<<" Passed\n";
	return 1;
}

int digit(){
	int re=0;
	while(X[T]>0){
		re+=X[T]%10;
		X[T]/=10;
	}
	X[T]=re;
	return 1;
}
int div(int a){
	if(X[T]%a) return 0;
	X[T]/=a;	
	return 1;
}
int add(int a){
	if(X[T]>1e18-a) return 0;
	X[T]+=a;	
	return 1;
}




void solve(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	while(T--){
		lli n=N[T];int re;
		re=digit();
		re=digit();
		
		re=ans();
		
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
			X[i]=myrand()%100000000;
			N[i]=myrand()%100000000;
		}
		solve();
		if(flag) break;
	}


	return 0;
}



