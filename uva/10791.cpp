#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef long long int lli;
lli maxi=1e6;
vector<lli>prim(maxi,1);
vector<lli>primes;
void sieve(){
    prim[0]=0;
    prim[1]=0;
    for(int i=2;i<maxi;i++){
        if(prim[i]==0)continue;
        primes.push_back(i);
        if(i>=sqrt(maxi)){
            continue;
        }
        for(int j=i+i;j<maxi;j+=i){
            prim[j]=0;
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli a;
   // sieve();
    int r=1;
    while(cin>>a){
        if(a==0)break;
        unordered_map<lli,lli>fact;
        while(a%2==0){
            fact[2]++;
            a/=2;
        }
        lli n=3;
        while(n<=sqrt(a)){
            while(a%n==0){
                fact[n]++;
                a/=n;
            }
            n+=2;
        }
        if(a>1){
            fact[a]++;
        }
        lli cont=0;
        for(auto n:fact){
            cont+=pow(n.first,n.second);
        }
        if(fact.size()==1)cont++;
        else if(fact.size()==0)cont=2;
        cout<<"Case "<<r++<<": "<<cont<<ENDL;

    }
}
