#include <iostream>
using namespace std;
bool uniOcc(int *arr, int arrSize)
{
    int l = 0, arrc[l], temp, k;

    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] > arr[j])
                temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    for (int i = 0; i < arrSize;)
    {
        k = 1;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] == arr[j])
            {
                k++;
            }
            else
            {
                break;
            }
        }
        arrc[l++] = k;
        i += k;
    }
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (arrc[i] == arrc[j])
            {
                k = 0;
                break;
            }
        }
    }

    if (k == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int arr[] = {1, 2, 2, 1, 1, 3};
    cout << uniOcc(arr, 6);
}