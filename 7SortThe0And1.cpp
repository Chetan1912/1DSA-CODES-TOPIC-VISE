#include <iostream>
using namespace std;
int main()
{
    int i = 0, j = 8 - 1;
    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};
    while (i <= j)
    {
        while (arr[i] == 0 && i < j)
        {
            i++;
        }
        while (arr[j] == 1)
        {
            j--;
        }

        // agar yaha tak pahuk gaye ho matlab h ki arr[i]==1 arr[j]==0;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << "  ";
    }
}