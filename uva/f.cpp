#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef long long int lli;
lli mod=1e9+7;
struct matrix
{
    long long c[2][2];
};
matrix I = {1, 0, 0, 1};
matrix A = {0, 0, 0, 0};
matrix R = {0, 1, 0, 0};
map<pair<int,pair<int,int>>,int>values;
matrix operator*(matrix a, matrix b)
{
    matrix C = A;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                C.c[i][j] = (C.c[i][j] + (a.c[i][k] * b.c[k][j]) % mod) % mod;
    return C;
}
matrix pow(matrix a, long long k)
{
    matrix ans = I;
    while (k)
    {
        if (k & 1)
            ans = ans * a;
        a = a * a;
        k /= 2;
    }
    return ans;
}
lli res2(lli a, lli b, lli n)
{
    if(values.count({a,{b,n}})){
        return values[{a,{b,n}}];
    }
    long long  p, q, a1, a2;
    p=q=1;
    a1=a;
    a2=b;
    if (n == 1)
    {
        values[{a,{b,n}}]=a1%mod;
        return a1%mod;
    }
    if (n == 2)
    {
        values[{a,{b,n}}]=a2%mod;
        return a2%mod;
    }
    matrix fin = A;
    fin.c[0][0] = a2;
    fin.c[0][1] = a1;
    matrix M = R;
    M.c[0][0] = p;
    M.c[1][0] = q;
    matrix ans = fin * pow(M, n - 2);
    values[{a,{b,n}}]=ans.c[0][0];
    return ans.c[0][0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a, b, c;
    cin >> a >> b;
    vector<lli> res(b);
    while (b--)
    {
        cin >> c;
        res[b]=c;
    }
    sort(res.begin(),res.end());
    lli last=1;
    lli lastaux=1;
    lli lastaux2=1;
    lli aux=0;
    //cout<<res2(0,1,4)<<ENDL;
    for (auto x:res)
    {
        lastaux=res2(lastaux,lastaux2,x-last+1);
        lastaux2=0;
        last=x;
        //cout<<lastaux<<" "<<lastaux2<<ENDL;
    }
    //cout<<a-last+2<<ENDL;
    lastaux=res2(lastaux,lastaux2,a-last+2);
    cout<<lastaux<<ENDL;

    return 0;
}
