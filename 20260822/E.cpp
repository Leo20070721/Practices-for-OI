#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
#define int long long
inline void _QuickStream(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
}

const bool _QuickStreamOpen=false;
const int _TEST=0;
//-------------------------------------
const int MAXN=6e5+12;
int N;
struct LightHouse{
    int bgnx;int bgny;
    int endx;int endy;
}LH[MAXN];
int in[MAXN],out[MAXN];
bool cmpLHbgnx(const int a,const int b){return LH[a].bgnx<LH[b].bgnx;}
bool cmpLHendx(const int a,const int b){return LH[a].endx<LH[b].endx;}

int addy[1005],suby[1005];
int ans;

signed main(){
    if(_QuickStreamOpen)_QuickStream();

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>LH[i].bgnx>>LH[i].bgny>>LH[i].endx>>LH[i].endy;
        in[i]=out[i]=i;
    }

    sort(in+1 ,in+1+N ,cmpLHbgnx);
    sort(out+1,out+1+N,cmpLHendx);

    int pos1=1,pos2=1;
    while(pos1<=N && pos2<=N){
        int lhin=in[pos1],lhout=out[pos2];

        if( LH[lhin].bgnx <= LH[lhout].endx ){
        	if(_TEST>=5)cout<<"Push:"<<in[pos1]<<"\n";
        	if(_TEST>=5){
        		for(int i=0;i<=1000;i++){
	            	if(addy[i]) cout<<i<<":"<<addy[i]<<"\n";
				}
			}
        	
            int getans=0;
            for(int i=0;i<=LH[lhin].bgny;i++){
            	getans+=addy[i]+suby[i];
			}
            ans+=getans*(getans-1)/2;    
            
            for(int i=LH[lhin].bgny+1;i<=LH[lhin].endy;i++){
            	getans+=suby[i];
                if(addy[i]>0) ans+=getans*addy[i]+addy[i]*(addy[i]-1)/2;
				getans+=addy[i];
            }
            if(_TEST>=5)cout<<getans<<"\n";

            

            addy[LH[lhin].bgny]++;
            suby[LH[lhin].endy+1]--;
            pos1++;

        }else{
        	 if(_TEST>=5)cout<<"Pop :"<<out[pos2]<<"\n";
            addy[LH[lhout].bgny]--;
            suby[LH[lhout].endy+1]++;
            pos2++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
