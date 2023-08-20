#include<bits/stdc++.h>
using namespace std;
string res(int k){
    int aux=1;
    if(k==1)aux=0;
    for(int r=2;r<=sqrt(k);r++){
        if(k%r==0){
            if(r==(k/r)){
                aux+=r;
            }else{
                aux+=(r+(k/r));
            }
        }
    }
    if(aux==k){
        return "PERFECT";
    }else if(aux<k){
        return "DEFICIENT";
    }
    return "ABUNDANT";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r;
    cout<<"PERFECTION OUTPUT\n";
    while(true){
        cin>>r;
        if(r==0)break;
        cout<<setw(5) << right<< r<<"  "<<res(r)<<"\n";
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
