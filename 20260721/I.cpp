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
int T,N;
int F[10005][3];

double calc(double x){
	double re=-INT_MAX;
	for(int i=1;i<=N;i++){
		re=max(re,x*x*F[i][0]+x*F[i][1]+F[i][2]);
	}
	return re;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;i++) cin>>F[i][0]>>F[i][1]>>F[i][2];
		
		double L=0,R=1000;
		while(R-L>1e-9){
			double lmid,rmid;
			lmid=(L*2+R*1)/3;
			rmid=(L*1+R*2)/3;
			
			if(calc(lmid)<calc(rmid)) R=rmid;
			else L=lmid;
		}
		
		printf("%.4lf\n",calc(L));
	}


	return 0;
}



