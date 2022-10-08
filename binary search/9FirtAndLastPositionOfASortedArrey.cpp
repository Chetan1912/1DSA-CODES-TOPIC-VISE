#include <iostream>
using namespace std;
int firstocc(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2; // why this is written check in dsa note page no 19;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            // go to the right side
            s = mid + 1;
        }
        else
        {
            // left me jao
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int Lastocc(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2; // why this is written check in dsa note page no 19;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            // go to the right side
            s = mid + 1;
        }
        else
        {
            // left me jao
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int n, my;
    cout << " ENTER THE N : ";
    cin >> n;
    int arr[n];
    cout << "PLEASE ENTER THE SORTED ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "PLEASE ENTER THE NUMBER YOU WANT TO FIND OCC OF FIRST AND LAST : ";
    cin >> my;

    cout << "FIRST MOST OCCERANCE : " << firstocc(arr, n, my) << endl;
    cout << "LAST  MOST OCCERANCE : " << Lastocc(arr, n, my);
}