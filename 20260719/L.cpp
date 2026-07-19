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
struct Water{
	int x;int y;
}water[100005]; 
bool cmp(Water a,Water b){
	return a.x<b.x;
}
deque< pair<int,int> > miny,maxy;
int N,D,ans=INT_MAX;

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}
	
	cin>>N>>D;
	for(int i=1;i<=N;i++){
		cin>>water[i].x>>water[i].y;
	}
	sort(water+1,water+1+N,cmp);
	
	int l=1,r=1;
	miny.push_back(make_pair(1,water[1].y));
	maxy.push_back(make_pair(1,water[1].y));
	while(true){		
		while(r<N && maxy.front().second-miny.front().second<D){
			r++;
			while(maxy.size()>0 && maxy.back().second<water[r].y) maxy.pop_back();
			maxy.push_back(make_pair(r,water[r].y));
			while(miny.size()>0 && miny.back().second>water[r].y) miny.pop_back();
			miny.push_back(make_pair(r,water[r].y));
			if(_TEST>=10)cout<<"r="<<r<<" maxy="<<maxy.front().second<<" maxypos="<<maxy.front().first<<" maxyx="<<water[maxy.front().first].x<<" maxysize="<<maxy.size()<<" | "<<" miny="<<miny.front().second<<" minypos="<<miny.front().first<<" minyx="<<water[miny.front().first].x<<" minysize="<<miny.size()<<"\n";
		}
		if(maxy.front().second-miny.front().second<D) break;
		
		if(_TEST>=10)cout<<"l="<<l<<"->r="<<r<<"\n";
		ans=min(ans,water[r].x-water[l].x);
		
		l++;
		while(maxy.size()>0 && maxy.front().first<l) maxy.pop_front();
		while(miny.size()>0 && miny.front().first<l) miny.pop_front();
	}
	
	if(ans==INT_MAX) cout<<"-1\n";
	else cout<<ans<<"\n"; 
	
	return 0;
}



