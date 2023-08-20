#include <bits/stdc++.h>
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
lli res(lli a, lli b, lli n)
{
    long long  p, q, a1, a2;
    p=q=1;
    a1=a;
    a2=b;
    if (n == 1)
    {
        
        return a1%mod;
    }
    if (n == 2)
    {
        return a2%mod;
    }
    matrix fin = A;
    fin.c[0][0] = a2;
    fin.c[0][1] = a1;
    matrix M = R;
    M.c[0][0] = p;
    M.c[1][0] = q;
    matrix ans = fin * pow(M, n - 2);
    return ans.c[0][0];
}
int main()
{
   cout<<res(3,5,4)<<endl;
}