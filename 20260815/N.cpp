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
lli H,W;
int M;
pair<int,int> rowT[200005],rowC[200005],colT[200005],colC[200005];
int rowCpos=1,colCpos=1;
int num[200005][2];
queue< pair<int,lli> > fin;
signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>H>>W>>M;
	num[0][0]=H;num[0][1]=W;
	for(int i=1;i<=M;i++){
		int T,A,X;cin>>T>>A>>X;
		if(T==1){
			num[rowT[A].second][0]--;
			rowT[A]=make_pair(i,X);
			rowC[A]=make_pair(X,i);
			num[X][0]++;
		}else{
			num[colT[A].second][1]--;
			colT[A]=make_pair(i,X);
			colC[A]=make_pair(X,i);
			num[X][1]++;
		}
	}
	
	sort(rowT+1,rowT+1+H);
	sort(rowC+1,rowC+1+H);
	sort(colT+1,colT+1+W);
	sort(colC+1,colC+1+W);
	
	lli sum=0;
	for(int i=0;i<=200000;i++){
		if(num[i][0]==0 && num[i][1]==0) continue;
		
		lli ans=0;
		
		if(num[i][0]!=0){
			for(;rowC[rowCpos].first==i&&rowCpos<=H;rowCpos++){
				int t=rowC[rowCpos].second;
				int L=0,R=W;
				while(L<R){
					int MID=(L+R+1)>>1;
					if(colT[MID].first<t) L=MID;
					else R=MID-1;
				}
				ans+=L;
			}			
		}
		
		if(num[i][1]!=0){
			for(;colC[colCpos].first==i&&colCpos<=W;colCpos++){
				int t=colC[colCpos].second;
				int L=0,R=H;
				while(L<R){
					int MID=(L+R+1)>>1;
					if(rowT[MID].first<t) L=MID;
					else R=MID-1;
				}
				ans+=L;
			}			
		}
		
		sum+=ans;
		if(ans) fin.push(make_pair(i,ans));		
	}
	
	if(H*W!=sum){
		if(!fin.empty() && fin.front().first==0) cout<<fin.size()<<"\n";
		else cout<<fin.size()+1<<"\n";
	}else cout<<fin.size()<<"\n";
	
	if(H*W!=sum){
		if(!fin.empty() && fin.front().first==0){
			cout<<"0 "<<H*W-sum+fin.front().second<<"\n";
			fin.pop(); 
		}else cout<<"0 "<<H*W-sum<<"\n";		
	}
	while(!fin.empty()){
		cout<<fin.front().first<<" "<<fin.front().second<<"\n";
		fin.pop();
	}

	return 0;
}



