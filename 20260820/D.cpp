#include <bits/stdc++.h>
using namespace std;
#define lli long long
//#define int long long
//-----------------------------------------
void _QuickStream(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
//------------------------------------------
int N,maxn,A[100005];
vector<int> prime;
int types[100005];
int games[24];

void init(){
	for(int i=2;i<=maxn;i++){
		if(types[i]==0){
			types[i]=1;
			prime.push_back(i);
		}
		
		for(int p:prime){
			if(i*p>maxn) break;
			types[i*p]=max(types[i*p],types[i]+1);
		}
	}
}



signed main(){
	_QuickStream();

	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		maxn=max(maxn,A[i]);
	}
	init();
	
	for(int i=1;i<=N;i++) games[types[A[i]]]++;
	
	int ans=0;
	for(int i=1;i<20;i++)
		if(games[i]%2) ans^=i;
		
	if(ans) cout<<"Anna\n";
	else cout<<"Bruno\n";
	
	
	return 0;
}

