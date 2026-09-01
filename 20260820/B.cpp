#include <bits/stdc++.h>
using namespace std;
#define lli long long
//-----------------------------------------
void _QuickStream(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
//------------------------------------------
deque < pair<lli,lli> > maxn,minn;

lli N,X,Y,ans;
int A[200005];

signed main(){
	_QuickStream();
	
	cin>>N>>X>>Y;
	for(int i=1;i<=N;i++) cin>>A[i];
	lli L=1,R=1;
	while(R<=N){
		while(!minn.empty() && minn.front().first<L) minn.pop_front();
		while(!maxn.empty() && maxn.front().first<L) maxn.pop_front();
		
		while(!minn.empty() && minn.back().second>A[R]) minn.pop_back();
		minn.push_back(make_pair(R,(A[R])));
		while(!maxn.empty() && maxn.back().second<A[R]) maxn.pop_back();
		maxn.push_back(make_pair(R,(A[R])));
		
		if(minn.front().second==Y && maxn.front().second==X){
			lli _L=L,_R=R;
			while(A[_R+1]<=X && A[_R+1]>=Y && _R<N){
				_R++;
				while(!minn.empty() && minn.back().second>A[_R]) minn.pop_back();
				minn.push_back(make_pair(_R,(A[_R])));
				while(!maxn.empty() && maxn.back().second<A[_R]) maxn.pop_back();
				maxn.push_back(make_pair(_R,(A[_R])));
			} 
//			cout<<"maxsize:"<<_L<<" "<<_R<<"\n";
			
			while(!minn.empty() && !maxn.empty() && minn.front().second==Y && maxn.front().second==X){
				lli l=min(minn.front().first,maxn.front().first);
				lli r=max(minn.front().first,maxn.front().first);
				ans+=(l-_L+1)*(_R-r+1);
//				cout<<l-_L+1<<"*"<<_R-r+1<<"\n";
				_L=l+1;
				if(minn.front().first<maxn.front().first) minn.pop_front();
				else if(minn.front().first==maxn.front().first){
					minn.pop_front();maxn.pop_front();
				}
				else maxn.pop_front();
			}			
			
			L=R=_R+1;
		}
		else{			
			if(minn.front().second>=Y && maxn.front().second<=X) R++;
			if(minn.front().second<Y || maxn.front().second>X) L++;
			if(L>R) R++;
		}
	}
	
	cout<<ans<<"\n";
}
