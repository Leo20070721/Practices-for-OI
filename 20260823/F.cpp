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
int N;
queue<lli> ans[24];

void out(lli ques){
    //cout<<"ques:"<<ques<<"\n";
    int i=1;
    while(ques>0){
        if(ques&1) cout<<i<<" ";
        i++;ques>>=1;
    }
    cout<<"\n";
    return;
}

int cnt(lli ques){
    int re=0;
    while(ques>0){
        if(ques&1) re++;
        ques>>=1;
    }
    return re;
}


signed main(){
    if(_QuickStreamOpen)_QuickStream();
    cin>>N;

    cout<<"0\n";
    for(int i=1;i<=((1<<N)-1);i++){
        ans[cnt(i)].push(i);
    }

    for(int i=1;i<=N;i++){
        while(ans[i].size()>0){
            out(ans[i].front());ans[i].pop();
            if(!ans[i+1].empty() && ans[i].size()>0){
                out(ans[i+1].front());ans[i+1].pop();
            }
        }
    }

    return 0;
}
