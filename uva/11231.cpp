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
const double PI=acos(-1);
int main()
{
    IO;
    lli n,m,c;
    while(cin>>n>>m>>c){
        if(n==0)break;
        lli r=(n-7)*(m-7);
        lli t=r/2;
        if(r%2){
            t++;
        }
        if(c==1)cout<<t<<ENDL;
        else cout<<r-t<<ENDL;
    }

    return 0;
}