find(x ^ n) % m;
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m)
{
    long long int ans = 1;

    while (n)
    { // odd ho
        if (n & 1)
        {
            ans = ((ans % m) * (x % m)) % m;
            n = n - 1;
        }
        else
        {
            x = ((1LL * x % m) * (1LL * x % m)) % m; // typecasted with the long long int
            n = n / 2;                               // can do n=n>>1;
        }
    }
    return ans;
}