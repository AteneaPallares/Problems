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
int maxi=1e6;
vector<lli>filled(maxi);
void fill(){
    filled[0]=0;
    filled[1]=1;
    filled[2]=1;
    for(int i=3;i<maxi;i++){
        filled[i]=filled[i-1]+filled[i-2];
    }

}
int main()
{
    IO;
    lli a, b, c, e;
  
    fill();
    while(true){
        cin>>a;
        if(a==-1)break;
        lli aux=filled[a+2]-1;
        lli aux2=filled[(a-1)+2]-1;
        aux2+=1;
        if(a<=1)aux2=1;
        cout<<aux<<" "<<aux+aux2<<endl;
    }
    return 0;
}