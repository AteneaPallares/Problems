#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef long long int lli;

lli res(lli a){
    queue<int>all;
    for(int i=1;i<=a;i++){
        all.push(i);
    }
    lli ok=0;
    while(all.size()>1){
        int t=all.front();
        all.pop();
        if(ok==1){
            all.push(t);
            ok=0;
        }else ok=1;

    }
    return all.front();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli n;
    vector<lli>opt;
    lli aux=1;
    while(aux<1e7){
        opt.push_back(aux);
        aux*=2;
    }
    while(cin>>n){
        if(n==0)break;
        if(n==1)cout<<1<<ENDL;
        else{
            auto mi=lower_bound(opt.begin(),opt.end(),n);
            lli ma=*mi;
            mi--;
            lli m=*mi;
            lli k=n-m;
            cout<<k*2<<ENDL;
        }
        // cout<<n<<" "<<res(n)<<ENDL;
    }
    return 0;
}
