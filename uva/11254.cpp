#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
pair<ll,ll>d(ll a){
    pair<ll,ll>res;
    ll maxi=sqrt(2*a);
    for(ll i=maxi;i>=1;i--){
        ll b=(2*a+i-(i*i));
        if(b%(2*i)==0){
            b/=(2*i);
            res.first=b;
            res.second=b+i-1;
            return res;
        }
    }
    return {a,a};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a;
    while(true){
        cin>>a;
        if(a==-1)break;
        auto res=d(a);
        cout<<a<<" = "<<res.first<<" + ... + "<<res.second<<"\n";
    }
    return 0;
}
