#include<bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef  long long int lli;
lli m=1e9+7;
lli maxi=1e6+2;
vector<lli>fact(maxi);
lli gcdExtended(lli a, lli b, lli *x, lli *y);
lli modInverse(lli b)
{
    lli x, y; 
    lli g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
 
    return (x%m + m) % m;
}
lli modDivide(lli a, lli b)
{
    a = a % m;
    lli inv = modInverse(b);
    if (inv == -1)
        return -1;
    else
    {
      lli c = (inv * a) % m ;
       return c;
    }
}
lli gcdExtended(lli a, lli b, lli *x, lli *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    lli x1, y1; 
    lli gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
lli expm(lli base, lli exp, lli mod) {
   lli res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}

void fillall(){
    fact[0]=1;
    fact[1]=1;
    for(lli i=2;i<maxi;i++){
        fact[i]=(fact[i-1]%m*i%m)%m;
    }
}

lli getcomb(lli a,lli b){
    lli x=fact[a]%m;
    lli y=(fact[b]%m*fact[a-b]%m)%m;
    //cout<<x<<" "<<y<<" "<<modDivide(x,y)<<ENDL;
    return modDivide(x,y);
}
lli getf(lli n,lli k){
    lli res=0;
    lli tot=0;
    for(int i=1;i<=k;i++){
        lli c=getcomb(k,i);
        lli r=expm(i,n,m);
        tot=(((c*r)%m+m)-res%m)%m;
        res=tot;
        //cout<<res<<ENDL;
    }
    return tot;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli a,b,c;
    cin>>a>>b>>c;
    fillall();
    //cout<<x<<" "<<y<<ENDL;
    if(c>b){
        cout<<0<<ENDL;
    }else{
        lli x=getcomb(b,c);
        lli y=getf(a,c);
        cout<<(x*y)%m<<ENDL;
    }
    
    return 0;
}
