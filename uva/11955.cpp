#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef unsigned long long int ll;
string getss(char a,char b,string x){
    string aux;
    for(auto n:x){
        if(n==a){
            aux="";
        }
        else if(aux.size()&&n==b)return aux;
        else aux+=n;
        
    }
    return aux;
}
ll maxi=1e3;
vector<vector<ll>>vec(maxi,vector<ll>(maxi));
void fill(){
    for(int i=0;i<maxi;i++){
        vec[i][1]=i;
        vec[i][0]=1;
    }
    for(int i=2;i<maxi;i++){
        for(int j=2;j<maxi;j++){
            vec[i][j]=vec[i-1][j-1]+vec[i-1][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a;
    cin>>a;
    fill();
    int y=1;
    while(a--){
        string s;
        cin>>s;
        string a=getss('(','+',s);
        string b=getss('+',')',s);
        string x=getss('^','-',s);
        int ax=stoi(x);
        int i=stoi(x);
        int j=0;
        cout<<"Case "<<y++<<": ";
        while(i>=0){
            ll x=vec[ax][j];
           // cout<<ENDL;
            //cout<<i<<" "<<j<<" "<<x<<ENDL;
            if(x>1){
                cout<<x<<"*";
            }
            if(i>=1){
                cout<<a;
                if(i>1){
                    cout<<"^"<<i;
                }
            }
            if(j>=1){
                if(i>=1){
                    cout<<"*";
                }
                cout<<b;
                if(j>1){
                    cout<<"^"<<j;
                }
            }
                
            
            i--;
            j++;
            if(i>=0)
            cout<<"+";
        }
        cout<<ENDL;
    }
    return 0;
}
