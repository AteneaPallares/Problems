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
int maxi = 1e6 + 500;
vector<pair<lli,lli>>tot(maxi);
void totient()
{

    for(int i=0;i<maxi;i++){
        tot[i].first=i;
        tot[i].second=i;
    }
    tot[1].first=0;
    tot[0].first=0;
    for(int i=2;i<maxi;i++){
        if(tot[i].first==i){
            tot[i].first=i-1;
             for(int j=2*i;j<maxi;j+=i){
                tot[j].first=(tot[j].first/i)*(i-1);
             }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    totient();
    lli a,b,c,h=1;
    cin>>a;

    while(a--){
        cin>>b;
        lli sum=0;
        vector<lli>xw;
        while(b--){
            cin>>c;
            xw.push_back(c);
        }
        lli j=0;
        sort(xw.begin(),xw.end());
        for(lli i=0;i<maxi;){
            if(tot[i].first>=xw[j]){
               // cout<<i<<" "<<tot[i].first<<endl;
                sum+=i;
                j++;
                if(j>=xw.size())break;
            }else i++;
        }
        cout<<"Case "<<h++<<": ";
        cout<<sum<<" Xukha"<<ENDL;
    }
    return 0;
}