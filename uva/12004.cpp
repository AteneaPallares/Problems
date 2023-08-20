#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef long long int lli;
int findSwaps(int n, int a[])
{
    int count = 0, i, j, temp, b[100000];
    for (i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}
void gr(lli n)
{
    int t[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = i;
    }
    lli r = 0;
    lli k = 0;
    while (true)
    {
        r += findSwaps(n, t);
        k++;
        if (!next_permutation(t, t + n))
            break;
    }
    lli gc = __gcd(r, k);
    // cout<<r<<" "<<k<<endl;
    if (k / gc == 1)
    {
        cout << r / gc << endl;
        return;
    }
    cout << r / gc << "/" << k / gc << endl;
    return;
}
void res(lli n)
{
    if (n == 1)
    {
        cout << 0 << ENDL;
        return;
    }
    lli t = n - 1;
    t = t / 4 + (t % 4 ? 1 : 0);
    // cout<<t<<endl;
    if ((n - 2) % 4 > 1)
    {
        if ((n - 2) % 4 == 3)
            cout << n * (t);
        else
        {
            cout << (n - 1) * (t);
        }
    }
    else
    {
        if ((n - 2) % 4 == 1)
            cout << n * (2*t-1) << "/2";

        else
        {
            cout << (n - 1) * (2*t-1) << "/2";
        }
    }
    cout << ENDL;
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli t;
    cin >> t;
    lli n;
    int i=1;
    while (t--)
    {
        // gr(n);
        cin>>n;
        cout<<"Case "<<i++<<": ";
        res(n);
    }
    return 0;
}
