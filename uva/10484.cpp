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
#define ull unsigned long long int
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
lli maxi=1e5;
vector<lli>prim(maxi+1,1);
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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a, b, c, d;
    sieve();
    while(cin>>a>>b){
        if(a==0&&b==0)break;
        unordered_map<int,int>fact1;
        int aux=a;
        for(auto n:primes){
            if(n>a)break;
            int auxp=n;
            while(aux/auxp){
                fact1[n]+=aux/auxp;
                auxp*=n;
            }
        }
        unordered_map<int,int>fact2;
        for(auto n:primes){
            if(n>b)break;
            while(b%n==0){
                fact2[n]++;
                b/=n;
            }
        }
        if(b>1){
            fact2[b]++;
        }
        lli res=1;
        lli c=0;
        for(auto &n:fact1){
            if(fact2.count(n.first)){
                n.second-=fact2[n.first];
                c++;
            }
            if(n.second<0){
                res=0;
                break;
            }
            res=res*(n.second+1);
        }
        if(c!=fact2.size())res=0;
        cout<<res<<ENDL;


    }
    return 0;
}