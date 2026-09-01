#include <bits/stdc++.h>
using namespace std;

int T;
int N,A[1003],ans;

int sol(int n){
	
}

signed main(){
	cin>>T;
	while(T--){
		cin>>N;ans=0;
		for(int i=1;i<=N;i++) cin>>A[i];
		for(int i=1;i<=N;i++) ans^=A[i];
		if(ans!=0 && N%2==0) ans=-1;
		
		cout<<ans<<"\n";
	}
}
