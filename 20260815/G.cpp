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
int A[200005],T;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		int ul=0,dl=0,N,now,lst;
		bool u=false,d=false,flag=true;
			
		cin>>N;
		for(int i=1;i<=N;i++) cin>>A[i];
		
		lst=A[1];	
		for(int i=2;i<=N;i++){
			now=A[i];
			if(u){
				if(now<lst){
					if(A[ul]<lst&&A[ul+1]<now){
						cout<<ul<<" "<<i<<"\n";
						flag=false;
						break;
					}else u=false;
				}
			}if(!u && now<lst){
				u=true;
				ul=i-1;
			}
			
			if(d){
				if(now>lst){
					if(A[dl]>lst&&A[dl+1]>now){
						cout<<dl<<" "<<i<<"\n";
						flag=false;
						break;
					}else d=false;
				}
			}if(!d && now>lst){
				d=true;
				dl=i-1;
			}
			cout<<now<<" "<<u<<":"<<ul<<"  "<<d<<":"<<dl<<"\n";
			lst=now;
		}
		if(flag) cout<<"-1\n";
	}

	return 0;
}



