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
const int MAXN=1e5+12;
int T,N,A[MAXN];
int L[MAXN],R[MAXN];
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>T;
	while(T--){
		queue<int> Q;
		cin>>N;
		for(int i=1;i<=N;i++){
			L[i]=R[i]=0;
			Q.push(i);
			cin>>A[i];
		}
		
		if(N==1){cout<<"Impossible\n";continue;}
		if(N==2){
			if(A[1]==1) cout<<"Possible\n2 1\n2 1\n";
			else cout<<"Impossible\n";
			continue;
		}
		if(N==3){
			if(A[1]==1&&A[2]==2&&A[3]==3) cout<<"Possible\n3 1 2\n2 3 1\n";
			else if(A[1]==1||A[2]==2||A[3]==3) cout<<"Impossible\n";
			else if(A[1]==3) cout<<"Possible\n3 1 2\n3 1 2\n";
			else cout<<"Possible\n2 3 1\n2 3 1\n";
			continue;
		}
		int now;
		for(now=1;now<=N;now++){
			if(Q.front()!=now && Q.front()!=A[now]){
				L[now]=Q.front();R[Q.front()]=now;	
				Q.pop();
			}else{
				if(Q.size()<=2) break;
				Q.push(Q.front());
				Q.pop();
				now--;
			}
		}
		
		vector<int> lst;
		while(!Q.empty()){
			lst.push_back(Q.front());
			Q.pop();
		}
		for(;now<=N;now++){
			bool flag=true;
			for(int i=1;i<now && flag;i++){
				if(A[now]==i) continue;
				
				if(R[i]==0){
					L[now]=i;R[i]=now;
//					cout<<now<<"->"<<i<<"\n";
					break;
				}
				
				int U=R[i];
				for(unsigned int p=0;p<lst.size();p++){
					int nxt=lst[p];
					if(nxt==0||nxt==i||R[nxt]) continue;
					if(U!=nxt && A[U]!=nxt){
						flag=false;
//						cout<<now<<"->"<<i<<"->"<<U<<"->"<<nxt<<"\n";
						L[U]=nxt;R[nxt]=U;
						L[now]=i;R[i]=now;
						lst[p]=0;
					}
				}
			}
		}
		
		
//		for(int i=1;i<=N;i++) cout<<L[i]<<" "; cout<<"\n";
//		for(int i=1;i<=N;i++) cout<<R[i]<<" "; cout<<"\n\n";
		
		cout<<"Possible\n";
		for(int i=1;i<=N;i++){
			cout<<R[i]<<" ";
			L[A[R[i]]]=i;
		}  cout<<"\n";
		for(int i=1;i<=N;i++) cout<<L[i]<<" "; cout<<"\n";
		
	}
	

	return 0;
}



