#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef unsigned long long int lli;
lli maxi=1e4+1;
vector<lli>pr(maxi,1);
vector<lli>primes;
void cribe(){
    pr[0]=0;
    pr[1]=0;
    for(int i=2;i<maxi;i++){
        if(pr[i]==0)continue;
        primes.push_back(i);
        if(i<sqrt(maxi))
        for(int j=i+i;j<maxi;j+=i){
            pr[j]=0;
        }
    }

}
lli getans(lli a,lli b){
    lli mult=1;
    lli i=a*a;
    lli aux2=b;
    if(b>a)return 0;
    vector<lli>x(primes.size(),0);
    while(i>1 && b>=1){
        //cout<<"---"<<i<<ENDL;
        lli ax=i;
        for(int j=0;j<primes.size();j++){
            lli n=primes[j];
            if(n>i)break;
            while(i%n==0){
                i/=n;
                x[j]++;
              //  cout<<primes[j]<<" "<<x[j]<<ENDL;
            }
        }
        i=ax;
        i-=(2*a-1);
       // cout<<i<<ENDL;
        a--;
        b--;
    }
    b=aux2;
     //cout<<"&&&&&&&&&&"<<ENDL;
    for(int i=0;i<primes.size();i++){
        lli aux=primes[i];
        while(b/aux){
            x[i]-=b/aux;
           //  cout<<aux<<" "<<x[i]<<ENDL;
            aux*=primes[i];
        }
    }
    lli res=1;
    //cout<<"***********"<<ENDL;
    for(int i=0;i<primes.size();i++){
        lli aux=primes[i];
        if(x[i]>0){
          //  cout<<aux<<" "<<x[i]<<ENDL;
            res*=pow(aux,x[i]);
        }
        
    }
    return res;
    
}
int main(){
    lli n,a,b;
    cin>>n;
    lli i=1;
    cribe();
    while(n--){
        cin>>a>>b;
        cout<<"Case "<<i++<<": ";
        cout<<getans(a,b)<<ENDL;
    }
    return 0;
}