#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef  long long int lli;
lli m=1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a,b,c,d,e;
    cin>>a>>b>>c;
    vector<vector<lli>>graph(a+1,vector<lli>());
    while(b--){
        cin>>d>>e;
        graph[d].push_back(e);
        graph[e].push_back(d);
    }
    
    vector<vector<lli>>aux(c+1,vector<lli>(a+1,0));
    aux[0][1]=1;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=a;j++){
            for(auto n:graph[j]){
                aux[i][j]+=aux[i-1][n];
            }
            aux[i][j]%=m;
        }
    }
    lli res=0;
    for(int i=1;i<=a;i++){
        res+=aux[c][i];
        res%=m;
    }
    cout<<res<<ENDL;


    return 0;
}
