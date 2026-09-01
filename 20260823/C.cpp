#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define Ld long double
//#define int long long
inline void _QuickStream(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
}

const bool _QuickStreamOpen=true;
const int _TEST=0;
//-------------------------------------
int T;
string sget;
int num[30],lst[30],sorted[30];
bool cmp(int a,int b){return num[a]>num[b];}
signed main(){
    if(_QuickStreamOpen)_QuickStream();

    cin>>T;
    for(int _t=1;_t<=T;_t++){
        memset(num,0,sizeof(num));
        bool flag=false;
        queue<int> pos[27];

        cin>>sget;cout<<"Case #"<<_t<<": ";
        vector<char> ans(sget.size());

        for(int i=0;i<sget.size();i++){
            num[sget[i]-'a']++;
            pos[sget[i]-'a'].push(i);
        }

        for(int i=0;i<27;i++){
                sorted[i]=i;
                lst[i]=num[i];
            if(num[i]*2>sget.size()){
                cout<<"IMPOSSIBLE\n";
                flag=true;
                break;
            }
        }if(flag) continue;

        sort(sorted,sorted+26,cmp);
        int used=0;
        queue<int> Q;Q.push(sorted[used++]);
        while(!Q.empty()){
            int now=Q.front();Q.pop();
            if(_TEST>=5)cout<<"TRIED:"<<char('a'+now)<<"\n";
            while(num[now]>0){
                while(lst[sorted[used]]==0)  used=(used+1)%26;
                if(num[sorted[used]]>0)Q.push(sorted[used]);
                int nxt=sorted[used];
                for(int i=1;i<=min(num[now],lst[nxt]);i++){
                    int putin=pos[nxt].front();pos[nxt].pop();
                    ans[putin]='a'+now;
                    if(_TEST>=5)cout<<"Replaced "<<putin<<":from "<<char('a'+nxt)<<" to "<<char('a'+now)<<"\n";
                }

                if(num[now]>=lst[nxt]){
                    num[now]-=lst[nxt];
                    lst[nxt]=0;
                    used=(used+1)%26;
                }else{
                    lst[nxt]-=num[now];
                    num[now]=0;
                }
            }
            if(_TEST>=5){
                for(int i=0;i<sget.size();i++) cout<<ans[i]; cout<<"\n";
            }
        }

        for(int i=0;i<sget.size();i++) cout<<ans[i]; cout<<"\n";
    }

    return 0;
}
