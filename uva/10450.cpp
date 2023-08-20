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
int maxi=60;
vector<lli>filled(maxi);
void fill(){
    filled[0]=2;
    filled[1]=3;
    for(int i=2;i<maxi;i++){
        filled[i]=filled[i-1]+filled[i-2];
    }

}
int main()
{
    IO;
    lli a, b, c, e;
  
    fill();
    cin>>a;
    int i=1;
    while(a--){
        cin>>b;
        cout<<"Scenario #"<<i++<<":"<<ENDL;
        cout<<filled[b-1]<<ENDL;
        cout<<ENDL;
    }
    return 0;
}