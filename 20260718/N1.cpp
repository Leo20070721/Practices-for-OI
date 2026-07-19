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
int N;
lli Mx[24];
set <pair<lli,lli> > visA,visB;
vector <pair<lli,lli> > ansA,ansB;
bitset <(1<<20)> ans;

void dfs(int end,int pos,lli L,lli R,lli vis){
	if(pos==end+1){
		if(pos-1<=N/2) {
			if(visA.find(make_pair(L-R,vis)) != visA.end()) return;
			visA.insert(make_pair(L-R,vis));
			ansA.push_back(make_pair(L-R,vis));
		}
		else{
			if(visB.find(make_pair(R-L,vis)) != visB.end()) return;
			visB.insert(make_pair(R-L,vis));
			ansB.push_back(make_pair(R-L,vis));
		}
		return ;
	}
	
	dfs(end,pos+1,L,R,vis<<1);
	dfs(end,pos+1,L+Mx[pos],R,(vis<<1)+1);
	dfs(end,pos+1,L,R+Mx[pos],(vis<<1)+1);
}

bool cmp(pair<lli,lli> a,pair<lli,lli> b){
	return a.first<b.first;
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
	
	sort(ansA.begin(),ansA.end(),cmp);
	sort(ansB.begin(),ansB.end(),cmp);
	
	if(_TEST>5){
		for(unsigned int i=0;i<ansA.size();i++){
			cout<<ansA[i].first<<" ";
		}cout<<"\n";
		for(unsigned int i=0;i<ansB.size();i++){
			cout<<ansB[i].first<<" ";
		}cout<<"\n";
	}
	
	
	unsigned int i=0,j=0;
	for(;i<ansA.size();i++){
		int temp=ansA[i].first;
		if(temp>0) break;
		while(j<ansB.size()){
			if(ansB[j].first<temp){
				j++;
			}else break;
		}
		unsigned int k=j;
		while(k<ansB.size()){
			if(ansB[k].first==temp){
				lli pos=(ansA[i].second<<(N-N/2))+ansB[k].second;
				if(_TEST>=10) cout<<"Catch:"<<temp<<" "<<i<<" "<<k<<"  "<<bitset<20>(pos)<<"\n";
				if(!ans[pos]){
					ans[pos]=true;
					if(_TEST>=5)cout<<bitset<20>(pos)<<"\n";
				}
				k++;
			}else break;
		}
	}
	
	cout<<ans.count()-1<<"\n";
	
	return 0;
}



