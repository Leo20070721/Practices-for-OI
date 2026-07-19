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
	freopen("P3799_4.in","r",stdin);
	//freopen(".out","w",stdout);
}
const bool _QuickStream=true;
const bool _FILE=false;
const int  _TEST=0;
//------------------------------------------
int N,bucket[5005],MAXL=0;
lli MOD=1000000007,ans;

lli times(lli a,lli b){
	return (a*b)%MOD;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N;
	for(int i=1;i<=N;i++){
		int iget;cin>>iget;bucket[iget]++;
	}	
	
	for(int i=5002;i>=1;i--){
		if(bucket[i]>1){
			MAXL=i;
			break;
		}
	}
		
	for(int i=2;i<=MAXL;i++){
		if(bucket[i]<2) continue;
		for(int j=1;j*2<=i;j++){
			
			if(bucket[j]==0) continue;
			if(i==j*2){
				if(bucket[j]<2) continue;
				ans=(  ans+times((bucket[i]*(bucket[i]-1)/2)%MOD,(bucket[j]*(bucket[j]-1)/2)%MOD)  )%MOD;
			}else{
				if(bucket[i-j]==0) continue;
				ans=(  ans+times(times((bucket[i]*(bucket[i]-1)/2)%MOD,bucket[j]),bucket[i-j])  )%MOD;
			}
			
		} 	
	}
	
	
	
	cout<<ans%MOD<<"\n";

	return 0;
}



