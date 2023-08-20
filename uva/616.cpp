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

int main()
{
    IO;
    lli n;
    set<lli>all;
    while(cin>>n)
    {
        if (n < 0)
            break;
        bool ok = false;
        lli ans = 0;
        for (int i = sqrt(n)+5; i >= 1; i--)
        {
            lli aux = n;
            if(ok)break;
            for (int q = 0; q <= i; q++)
            {
                
                if (aux % i == 1)
                {
                    aux -= (aux-1) / i + 1;
                }
                else if (aux % i == 0 && q == i)
                {
                    ok = true;
                    ans = i;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        if(ok){
            all.insert(ans);
            cout<<n<<" coconuts, "<<ans<<" people and 1 monkey"<<ENDL;
        }else{
            cout<<n<<" coconuts, no solution"<<ENDL;
        }
    }
    return 0;
}