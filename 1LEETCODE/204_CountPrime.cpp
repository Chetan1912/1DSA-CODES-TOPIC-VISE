// 204. Count Primes
//     Medium

//     5528

//     1097

//     Add to List

//         Share
//             Given an integer n,
//     return the number of prime numbers that are strictly less than n.

//            Example 1 :

//     Input : n = 10 Output : 4 Explanation : There are 4 prime numbers less than 10,
//             they are 2, 3, 5, 7. Example 2 :

//     Input : n = 0 Output : 0 Example 3 :

//     Input : n = 1 Output : 0

//                 Constraints :

//                 0 <= n <= 5 * 106
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = 0;
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                cnt++;
                for (int j = 2 * i; j < n; j = j + i)
                {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};

// not a optimal solution
//  int count=0;
//         int prime=1;
//         for(int num=2; num<n; num++)
//         {
//             prime=1;
//             if(num==2)
//             {count++;
//             continue;
//             }
//             for(int i=2; i<num; i++)
//             {
//                 if(num%i==0)
//                 {
//                    prime=0;
//                 }

//             }
//             if(prime!=0)
//             {
//                 count++;
//             }

//         }
//         return count;