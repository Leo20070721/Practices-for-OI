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
string S,T;
bool del[3000006];int ans=0,ans2=INT_MAX;
signed main(){
    if(_QuickStreamOpen)_QuickStream();

    cin>>T>>S;
    int pos1=0,pos2=0;
    while(pos1<T.size() && pos2<S.size()){
        if(T[pos1]<S[pos2]) break;

        if(pos1>0 && del[pos1-1]==false && T[pos1]<S[pos2-1]){
            ans2=min(ans2,ans+1);
        }

        if(T[pos1]==S[pos2]){
            if(pos2+1!=S.size()){pos1++,pos2++;}
            else{ del[pos1]==true;ans++;pos1++;}
        }
        else {del[pos1]==true;ans++;pos1++;}
    }

    cout<<min(ans,ans2)<<"\n";

    return 0;
}

