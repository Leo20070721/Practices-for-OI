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
int T;
int num[10],cnt,iget;
void init(){
	int sum=0;cnt=0;
	for(int i=0;i<10;i++) num[i]=0;
	for(int i=0;i<9;i++){
		cout<<"? "<<i<<i<<i<<i<<endl;
		cin>>num[i];		
		sum+=num[i];
		if(num[i]) cnt++;
		if(sum==4) break;
	}
	if(sum<4){
		num[9]=4-sum;
		cnt++;
	}
}

signed main(){
	if(_QuickStream){_QuickStreamOpen();}
	if(_FILE){_OpenFiles();}

	cin>>T;
	while(T--){
		init();
//		for(int i=0;i<10;i++) cout<<num[i]<<" "; cout<<"\n"<<cnt<<"\n";
		switch(cnt){
			case 1:{
				for(int i=0;i<10;i++)
					if(num[i]) cout<<"! "<<i<<i<<i<<i<<endl;
				break;
			}
			case 2:{
				bool flag=false;
				int a=0,b=0,x=0;
				for(int i=0;i<10;i++){
					if(!flag&&num[i]==2) flag=true;
					if(a && num[i]) b=i;
					if(!a && num[i]) a=i;					
					if(!num[i]) x=i;
				}
				if(num[b]>num[a]) swap(a,b);
				
				if(flag){//aabb
					cout<<"? "<<a<<a<<x<<x<<endl;
					cin>>iget;
					
					if(iget==2) 	 cout<<"! "<<a<<a<<b<<b<<endl;
					else if(iget==0) cout<<"! "<<b<<b<<a<<a<<endl;
					else{
						cout<<"? "<<x<<a<<a<<x<<endl;
						cin>>iget;
						if(iget==0) 	 cout<<"! "<<a<<b<<b<<a<<endl;
						else if(iget==2) cout<<"! "<<b<<a<<a<<b<<endl;
						else{
							cout<<"? "<<a<<x<<a<<x<<endl;
							cin>>iget;
							if(iget==2) cout<<"! "<<a<<b<<a<<b<<endl;
							else 		cout<<"! "<<b<<a<<b<<a<<endl;
						}
					}
				}else{//aaab
					cout<<"? "<<b<<x<<x<<x<<endl;
					cin>>iget;
					if(iget){cout<<"! "<<b<<a<<a<<a<<endl;break;}
					cout<<"? "<<x<<b<<x<<x<<endl;
					cin>>iget;
					if(iget){cout<<"! "<<a<<b<<a<<a<<endl;break;}
					cout<<"? "<<x<<x<<b<<x<<endl;
					cin>>iget;
					if(iget){cout<<"! "<<a<<a<<b<<a<<endl;break;}
					else 	 cout<<"! "<<a<<a<<a<<b<<endl;
				}
				
				break;
			}
			case 3:{
				int a=0,b=0,c=0,x=0;
				for(int i=0;i<10;i++){
					if(num[i]==2) a=i;
					if(b && num[i]==1) c=i;
					if(!b && num[i]==1) b=i;
					if(!num[i]) x=i;
				}
				
				cout<<"? "<<a<<a<<x<<x<<endl;
				cin>>iget;
				if(iget==2){
					cout<<"? "<<a<<a<<b<<c<<endl;
					cin>>iget;
					if(iget==4) cout<<"! "<<a<<a<<b<<c<<endl;
					else 		cout<<"! "<<a<<a<<c<<b<<endl;
				}else if(iget==0){
					cout<<"? "<<b<<c<<a<<a<<endl;
					cin>>iget;
					if(iget==4) cout<<"! "<<b<<c<<a<<a<<endl;
					else 		cout<<"! "<<c<<b<<a<<a<<endl;
				}else{
					cout<<"? "<<b<<b<<x<<x<<endl;
					cin>>iget;
					if(iget==1){
						cout<<"? "<<a<<b<<a<<x<<endl;
						cin>>iget;
						if(iget==0) 	 cout<<"! "<<b<<a<<c<<a<<endl;
						else if(iget==1) cout<<"! "<<b<<a<<a<<c<<endl;
						else if(iget==2) cout<<"! "<<a<<b<<c<<a<<endl;
						else			 cout<<"! "<<a<<b<<a<<c<<endl;
					}else{
						cout<<"? "<<a<<x<<a<<b<<endl;
						cin>>iget;
						if(iget==0) 	 cout<<"! "<<c<<a<<b<<a<<endl;
						else if(iget==1) cout<<"! "<<a<<c<<b<<a<<endl;
						else if(iget==2) cout<<"! "<<c<<a<<a<<b<<endl;
						else			 cout<<"! "<<a<<c<<a<<b<<endl;
					}
				}				
				break;
			}
			case 4:{
				int a=0,b=0,c=0,d=0,x=0;
				for(int i=0;i<10;i++){
					if(c && num[i]) d=i;
					else if(b && num[i]) c=i;
					else if(a && num[i]) b=i;
					else if(!a && num[i]) a=i;
					if(!num[i]) x=i;
				}
				
				cout<<"? "<<a<<a<<b<<b<<endl;
				cin>>iget;
				if(iget==0) swap(a,b);
				if(iget==1){
					cout<<"? "<<a<<a<<x<<x<<endl;
					cin>>iget;
					if(iget==0){ swap(a,c); swap(b,d);}
					cout<<"? "<<a<<b<<c<<x<<endl;
					cin>>iget;
					
					if(iget==0) 	 cout<<"! "<<b<<a<<d<<c<<endl;
					else if(iget==1) cout<<"! "<<b<<a<<c<<d<<endl;
					else if(iget==2) cout<<"! "<<a<<b<<d<<c<<endl;
					else			 cout<<"! "<<a<<b<<c<<d<<endl;
					
					break;
				}
				
				cout<<"? "<<c<<c<<d<<d<<endl;
				cin>>iget;
				if(iget==0) swap(c,d);
				
				cout<<"? "<<a<<c<<b<<x<<endl;
					cin>>iget;
					if(iget==0) 	 cout<<"! "<<c<<a<<d<<b<<endl;
					else if(iget==1) cout<<"! "<<c<<a<<b<<d<<endl;
					else if(iget==2) cout<<"! "<<a<<c<<d<<b<<endl;
					else			 cout<<"! "<<a<<c<<b<<d<<endl;
				
				break;
			}
		}
	}

	return 0;
}



