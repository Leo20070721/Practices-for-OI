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
int N,K;
double L[100005];

bool check(double q){
	if(q==0) return true;
	int sum=0;
	for(int i=1;i<=N;i++) sum+=floor(L[i]/q);
	return sum>=K;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>K;
	for(int i=1;i<=N;i++) cin>>L[i];
	
	double L=0,R=100000005;
	while(R-L>0.005){
		double mid=(L+R)/2;
		if(check(mid)) L=mid;
		else R=mid; 
	}
	printf("%.2lf\n",L);

	return 0;
}



