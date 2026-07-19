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
const int  _TEST=10;
//------------------------------------------
int N;
lli Mx[24],ans;
set <pair<lli,lli> > visA,visB;
vector <lli> ansA,ansB;

void dfs(int end,int pos,lli L,lli R,lli vis){
	if(pos==end+1){
		if(pos-1<=N/2) {
			if(visA.find(make_pair(L-R,vis)) != visA.end()) return;
			visA.insert(make_pair(L-R,vis));
			ansA.push_back(L-R);
		}
		else{
			if(visB.find(make_pair(R-L,vis)) != visB.end()) return;
			visB.insert(make_pair(R-L,vis));
			ansB.push_back(R-L);
		}
		return ;
	}
	
	dfs(end,pos+1,L,R,vis<<1);
	dfs(end,pos+1,L+Mx[pos],R,(vis<<1)+1);
	dfs(end,pos+1,L,R+Mx[pos],(vis<<1)+1);
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>Mx[i];
	}
	
	dfs(N/2,1    ,0,0,0);
	dfs(N  ,N/2+1,0,0,0);
	
	
	
	sort(ansA.begin(),ansA.end());
	sort(ansB.begin(),ansB.end());
	
	if(_TEST>5){
		for(unsigned int i=0;i<ansA.size();i++){
			cout<<ansA[i]<<" ";
		}cout<<"\n";
		for(unsigned int i=0;i<ansB.size();i++){
			cout<<ansB[i]<<" ";
		}cout<<"\n";
	}
	
	
	unsigned int i=0,j=0;
	while(i<ansA.size()){
		int temp=ansA[i++],temp_cnt=1;
		while(i<ansA.size()){
			if(ansA[i]==temp){
				i++;
				temp_cnt++;
			}else break;
		}
		
		while(j<ansB.size()){
			if(ansB[j]<temp){
				j++;
			}else break;
		}
		int temp_cnt2=0;
		while(j<ansB.size()){
			if(ansB[j]==temp){
				j++;
				temp_cnt2++;
			}else break;
		}
		if(temp>0) break;
		if(_TEST>=10)cout<<temp<<":"<<temp_cnt<<" "<<temp_cnt2<<"\n";
		if(temp==0) ans+=temp_cnt*temp_cnt2-1;
		else ans+=temp_cnt*temp_cnt2;		
	}
	
	cout<<ans<<"\n";
	
	return 0;
}



