#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef  long long int lli;
lli getm(vector<string>&r,int i,int j){
    vector<pair<int,int>>pos={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    lli res=0;
    for(auto n:pos){
        auto x=i+n.first;
        auto y=j+n.second;
        
        if(x>=0&&y>=0&&x<r.size()&&y<r[0].size()){
           // cout<<x<<" "<<y<<ENDL;
            if(r[x][y]=='1'){
                r[x][y]='2';
                res+=getm(r,x,y)+1;
            }
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli a,b,c,d;
    cin>>a;
    cin.ignore();
    string s;
    getline(cin,s);
    while(a--){
        vector<string>r;
        while(getline(cin,s)){
            if(!s.size())break;
            r.push_back(s);

        }
        lli maxi=0;
        for(int i=0;i<r.size();i++){
            for(int j=0;j<r[0].size();j++){
                //cout<<r[i][j];
                if(r[i][j]=='1'){
                    r[i][j]='2';
                    maxi=max(maxi,getm(r,i,j)+1);
                }
              
            }
            //cout<<ENDL;
        }
        cout<<maxi<<ENDL;
        if(a>0)cout<<ENDL;

    }
    return 0;
}
