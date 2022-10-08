#include <iostream>
using namespace std;
bool linearsearch(int arr[], int size, int key)
{ // base size
    if (key == arr[0])
    {
        return 1;
    }
    if (size == 0) //  can write size==1
    {
        return 0;
    }

    bool is = linearsearch(arr + 1, size - 1, key);
    return is;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -11};
    bool found = linearsearch(arr, 10, 0);
    cout << found;
}