#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<lli, lli>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (lli i = (a); i < (n); ++i)
#define FORN(i, a, n) for (lli i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;
lli val=1e9;
void mini(lli i,lli sum, lli all,lli sum2, vector<lli>&dat){
    if(i>=dat.size()){
        if((ceil(double(dat.size())/2.0))-1<=all){
            val=min(val,sum-sum2);
        }
        return;
    }
    mini(i+1,sum,all+1,sum2+dat[i],dat);
    mini(i+1,sum,all,sum2,dat);
}
lli maximo=1e6;
vector<int>primes;
vector<bool>prim(maximo,1);
void sieve(){
    prim[0]=0;
    //primes.push_back(1);
    for(int i=2;i<sqrt(maximo);i++){
        if(prim[i]==0)continue;
        primes.push_back(i);
        for(int j=i+i;j<maximo;j+=i){
            prim[j]=0;
        }
    }
    for(int j=sqrt(maximo);j<maximo;j++){
        if(prim[j]==1)
            primes.push_back(j);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    lli a,b;
    while(true){
        cin>>b;
        if(b==0)break;
        bool ok=false;
        for(auto n:primes){
            lli aux=b-n;
            if(aux>=0 && aux<prim.size() && prim[aux]==1){
                cout<<b<<" = "<<n<<" + "<<aux<<ENDL;
                ok=true;
                break;
            }
        }
        if(!ok){
            cout<<"Goldbach's conjecture is wrong."<<ENDL;
        }
    }
    return 0;
}