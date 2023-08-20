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
lli maxi=101;
vector<vector<int>>com(maxi,vector<int>(maxi,0));
void fill(){
    for(int i=0;i<maxi;i++){
        com[i][0]=1;
        com[i][1]=i;
        com[i][i]=1;
    }
    for(int i=2;i<maxi;i++){
        for(int j=2;j<maxi;j++){
            com[i][j]=com[i-1][j-1]+com[i-1][j];
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill();
    lli a,b,c;
    while(cin>>a){
        lli sum=1;
        cin>>b;
        while(b--){
            cin>>c;
            sum*=com[a][c];
            a-=c;
        }
        cout<<sum<<ENDL;
    }
    return 0;
}