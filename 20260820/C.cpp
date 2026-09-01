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
int N;
vector<int> sons[2003];
int fa[2003],gpa[2003];
int dis[2003][2003];
int cnt[2003][2];
bool vis[2003];

void makefa(int now){
	for(int i=1;i<=N;i++){		
		if(dis[now][i]==1){
			if(fa[now]==i) continue;
			else if(dis[gpa[now]][i]==1){
				fa[now]=i;
				sons[i].push_back(now);
			}else{
				fa[i]=now;
				gpa[i]=fa[now];
				sons[now].push_back(i);	
			}
		}
	}
}

void DFS(int now){
	if(vis[now]) return;
	vis[now]=true;
	
	cout<<"? "<<now<<endl;
	for(int i=1;i<=N;i++){
		cin>>dis[now][i];
		if(dis[now][i]==1) cnt[now][0]++;
		if(dis[now][i]==2) cnt[now][1]++;
	}
	
	makefa(now);
		
	if(cnt[now][1]<=cnt[now][0]){
		for(int i=1;i<=N;i++){
			if(gpa[now]==i) continue;
			gpa[i]=now;
			if(dis[now][i]==2) DFS(i);
		}
	}else{
		for(int i=1;i<=N;i++){
			if(dis[now][i]==1) DFS(i);
		}
	}		
}

void ans(int now){
	for(int son:sons[now]){
		cout<<now<<" "<<son<<endl;
		ans(son);
	}
}

signed main(){
	_QuickStream();

	cin>>N;
	vis[0]=true;DFS(1);
	
	cout<<"!"<<endl;
	ans(1);

	return 0;
}

