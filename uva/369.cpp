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
vector<vector<lli>>filled(101,vector<lli>(101,0));
void fill(){
    for(int i=1;i<101;i++){
        filled[i][0]=0;
        filled[i][1]=i;
        filled[1][i]=0;
    }
    filled[1][1]=1;
    for(int i=2;i<101;i++){
        for(int j=2;j<101;j++){
            filled[i][j]=filled[i-1][j-1]+filled[i-1][j];
        }
    }

}
int main()
{
    IO;
    lli a, b, c, e;
  
    fill();
    while(true){
        cin>>a>>b;
        if(a==0&&b==0)break;
        cout<<a<<" things taken "<<b<<" at a time is "<<filled[a][b]<<" exactly."<<ENDL;

    }
    return 0;
}