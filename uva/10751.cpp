#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    cin>>a;
    while(a--){
        cin>>b;
        if(b<2){
            cout<<fixed<<setprecision(4)<<0;
        }else{
            double x=sqrt(2);
            int t=(b-2)*(b-2);
            double res=double(t)*x;
            res+=double(b*b)-double(t);
            cout<<fixed<<setprecision(4)<<res;
        }
        if(a==0){
             cout<<"\n";
        }else{
             cout<<"\n\n";
        }


    }
    return 0;
}
