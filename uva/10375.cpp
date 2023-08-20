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
int maxi = 1e5 + 1;
vector<lli> sie(maxi, 1);
vector<pair<lli, lli>> primes;
void sieve()
{
    sie[0] = 0;
    sie[1] = 0;
    for (int i = 2; i < maxi; i++)
    {
       
        if(i>=sqrt(maxi)&&sie[i]==1){
            primes.pb({i, 0});
            continue;
            
        }
        if(i>=sqrt(maxi)||sie[i]==0)continue;
        primes.pb({i, 0});
        for (int j = i + i; j < maxi; j += i)
        {
            sie[j] = 0;
        }
    }

}
void aut(lli a, lli r)
{
    //cout<<"##"<<a<<endl;
    for (auto &m : primes)
    {
       
        auto n = m.first;
        if(a<n)break;
        lli count = 0;
        lli h=n;
        while (a/h)
        {
            count += (a / h);
            h*=n;
        }
        m.second += r * count;
       // cout<<a<<" "<<n<<" "<<m.second<<endl;
        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a, b, c, d;
    sieve();
    //cout<<primes[primes.size()-1].first<<endl;
    while (cin >> a >> b >> c >> d)
    {
        vector<lli> ax = {a, (c - d), (d)};
        vector<lli> ab = {c, (a - b), (b)};
        for (auto n : ax)
        {
            //cout<<"^^^"<<ENDL;
            //cout<<n<<endl;
            aut(n, 1);
        }

        for (auto n : ab)
        {
            aut(n, -1);
        }
        double ans = 1;
        for (auto &n : primes)
        {
            if (n.second != 0){
                ans *= pow(n.first, n.second);
                n.second=0;
            }
                
        }
        cout << fixed << setprecision(5) << ans << ENDL;
    }

    return 0;
}