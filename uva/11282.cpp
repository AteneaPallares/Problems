#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef unsigned long long int lli;
lli maxi=22;
vector<vector<lli>>com(maxi,vector<lli>(maxi));
vector<lli>de(maxi);
void fillall(){
    for(int i=0;i<maxi;i++){
        com[i][1]=i;
        com[i][0]=1;
    }
    for(int i=2;i<maxi;i++){
        for(int j=2;j<maxi;j++){
            com[i][j]=com[i-1][j]+com[i-1][j-1];
        }
    }
    de[0]=1;
    de[1]=0;
    for(int i=2;i<maxi;i++){
        de[i]=(i-1)*(de[i-1]+de[i-2]);
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli a,b;
    fillall();
    while(cin>>a>>b){
        lli sum=0;
       // cout<<a<<" "<<com[20][20]<<" "<<de[a-i]<<ENDL;
        for(int i=0;i<=b;i++){
            
            sum+=com[a][i]*de[a-i];
        }
        cout<<sum<<ENDL;

    }

    
    return 0;
}
