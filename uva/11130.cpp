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
    lli a,b,v,A,s;
    while(cin>>a>>b>>v>>A>>s){
        if(a==0)break;
        lli t=(v*s)/2;
        lli dy=(cos(double(A)*PI/180.0)*double(t));
        lli dx=(sin(double(A)*PI/180.0)*double(t));
        // cout<<dx<<" "<<dy<<endl;
        lli re=dx>=(b/2)?1:0;
        dx-=(b/2);
        if(dx>=0){
            re+=dx/b;
        }
        lli rey=dy>=(a/2)?1:0;
        dy-=(a/2);
        if(dy>=0){
            rey+=dy/a;
        }
        cout<<rey<<" "<<re<<ENDL;
        

    }
    return 0;
}