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
    while(cin>>a){
        cin>>b;
        int dist=distance(primes.begin(),lower_bound(primes.begin(),primes.end(),a));
        int dist2=distance(primes.begin(),lower_bound(primes.begin(),primes.end(),b));
        pair<int,int>m{-1,-1};
        pair<int,int>m2{-1,-1};
        lli aux=0,aux2=1e6;
        bool ok=false;
        bool ok2=false;
        //cout<<dist<<" "<<dist2<<ENDL;
        for(int i=dist;i<dist2;i++){
            if(aux2>primes[i+1]-primes[i]){
                aux2=primes[i+1]-primes[i];
                m.first=primes[i];
                m.second=primes[i+1];
                if(m2.first==-1){
                    aux=primes[i+1]-primes[i];
                    m2.first=primes[i];
                    m2.second=primes[i+1];
                }
            }else
                if(aux<primes[i+1]-primes[i]){
                aux=primes[i+1]-primes[i];
                m2.first=primes[i];
                m2.second=primes[i+1];
            }
        }
        if(m.first!=-1&&m.second!=-1){
            cout<<m.first<<","<<m.second<<" are closest, "<<m2.first<<","<<m2.second<<" are most distant."<<ENDL;
        }else{
            cout<<"There are no adjacent primes."<<ENDL;
        }
    }
    return 0;
}