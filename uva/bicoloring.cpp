#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef  long long int lli;
bool isbi(unordered_map<int,unordered_map<int,int>>&graph,unordered_map<int,int>&ok,int n){
    if(ok[n]==0){
        ok[n]=1;
    }
    for(auto m:graph[n]){
        if(ok[m.first]!=ok[n]){
            if(ok[m.first]==0){
                ok[m.first]=ok[n]==1?2:1;
                bool x=isbi(graph,ok,m.first);
                if(!x)return false;
            }
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli a,b,c,d;
    while(cin>>a){
        if(a==0)break;
        cin>>b;
        unordered_map<int,unordered_map<int,int>>graph;
        unordered_map<int,int>ok;
        while(b--){
            cin>>c>>d;
            graph[c][d]=0;
            graph[d][c]=0;
        }
        if(isbi(graph,ok,0)){
            cout<<"BICOLORABLE."<<ENDL;
        }else{
            cout<<"NOT BICOLORABLE."<<ENDL;
        }
    }
    return 0;
}
