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
const int MAXS=4e5+24;
int N,Q;

priority_queue< pair<int,lli> , vector< pair<int,lli> > , greater< pair<int,lli> > > pre;
queue< pair<int,lli> > sub;
vector< pair<int,lli> > num,sum;

int findnum(int pos){
	int L=0,R=num.size()-1;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(num[mid].first<=pos) L=mid;
		else R=mid-1;
	}
	return L;
}
int findsum(int pos){
	int L=0,R=sum.size()-1;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(sum[mid].first<=pos) L=mid;
		else R=mid-1;
	}
	return L;
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>N>>Q;
	for(int i=1;i<=N;i++){		
		int L,R;lli val;cin>>L>>R>>val;
		pre.push(make_pair(L,val));
		pre.push(make_pair(R,-val));
	}
	int nowpos=-1,add=0;
	while(!pre.empty()){
//		cout<<pre.top().first<<":"<<pre.top().second<<"\n";
		if(nowpos!=pre.top().first){
			if(nowpos!=-1){
				sub.push(make_pair(nowpos,add));
			}
			nowpos=pre.top().first;
			add=pre.top().second;
			pre.pop();
			continue;
		}
		add+=pre.top().second;
		pre.pop();
	} 
	sub.push(make_pair(nowpos,add));
//	cout<<"-----------------------------------\n";
	int nxtpos=0;nowpos=-1;lli nownum=0;
	while(!sub.empty()){
		nxtpos=sub.front().first;
				
		num.push_back(make_pair(nowpos,nownum));
		if(sum.size()==0) sum.push_back(make_pair(nxtpos-1,0));
		else sum.push_back(make_pair(nxtpos-1,sum[sum.size()-1].second+ (nxtpos-nowpos)*nownum ));
		//cout<<nowpos<<"->"<<nxtpos<<":"<<nownum<<"\n";
		nowpos =nxtpos;
		nownum+=sub.front().second;
		
//		cout<<sub.front().first<<"-"<<sub.front().second<<"\n";
		sub.pop();
	} 
	num.push_back(make_pair(nowpos,nownum));
//	cout<<"-----------------------------------\n";
//	for(unsigned int i=0;i<num.size();i++){
//		cout<<num[i].first<<"="<<num[i].second<<"\n";
//	}cout<<"-----------------------------------\n";
//	for(unsigned int i=0;i<sum.size();i++){
//		cout<<sum[i].first<<"+"<<sum[i].second<<"\n";
//	}
	
	for(int i=1;i<=Q;i++){		
		int L,R;cin>>L>>R;
		int nlpos=findnum(L-1),nrpos=findnum(R-1);
		int slpos=findsum(L-1),srpos=findsum(R-1);
		cout<<sum[srpos].second-sum[slpos].second+num[nlpos].second*(sum[slpos].first-L+1)-num[nrpos].second*(sum[srpos].first-R+1)<<"\n";
//		cout<<"("<<nlpos<<"->"<<nrpos<<","<<slpos<<"->"<<srpos<<"):";
//		cout<<sum[srpos].second-sum[slpos].second;
//		cout<<"+"<<num[nlpos].second*(sum[slpos].first-L+1);
//		cout<<"-"<<num[nrpos].second*(sum[srpos].first-R+1)<<"\n";
	}

	return 0;
}



