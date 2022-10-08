long long int myPow(long long int x, long long int n)
{
    long long int ans = 1;
    long long nn = n;

    if (nn < 0)
    {
        nn = (-1) * nn;
    }
    while (nn)
    {
        if (nn % 2)
        {
            ans = (ans % 1000000007 * x % 1000000007) % 1000000007; // used because the integer will be larger innof than return 10^9+7;
            nn = nn - 1;
        }
        else
        {
            x = (x % 1000000007 * x % 1000000007) % 1000000007; // used the modulo arithmatic;
            nn = nn / 2;
        }
    }
    if (n < 0)
    {
        ans = 1.0 / ans;
    }
    return ans;
}

long long int nthTermOfGP(int N, int A, int R)
{

    long long int GP = (A % 1000000007 * myPow(R, (N - 1)) % 1000000007) % 1000000007;
    return GP;
}