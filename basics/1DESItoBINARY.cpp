// NOTE ==> IN THIS PROGRAM IT IS NOT WORKING PROPERLY IN THIS MINGW COMPILER SO DO EXECUTE IT IN THE ONLINE COMPILER
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <iostream>
using namespace std;
#include <math.h>
int main()
{
    int n; // used long long because its limit is high than the integer
    int ans = 0;

    cout << "please enter the decimal no  n : ";
    cin >> n;
    int temp = n;
    int bit; // the use of bit is to find the last digit of the binary example for 10 --> 1010 --> bit = 0
    for (int i = 0; n != 0; i++)
    {
        bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1; // this part right sifts the bit
    }
    cout << "the binarry of " << temp << "is " << ans << endl;
}