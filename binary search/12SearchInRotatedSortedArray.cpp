// this is not the actual code this is problem of code studio 131

int pivot(vector<int> &arr, int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s; // can also return the : e : because both are equal;
}
int binarysearch(vector<int> &arr, int start, int end, int key)
{
    int s = start, e = end;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int findPosition(vector<int> &arr, int n, int k)
{
    int pivot1 = pivot(arr, n);
    if (k >= arr[pivot1] && k <= arr[n - 1])
    {
        // binary search in the  second graf line
        return binarysearch(arr, pivot1, n - 1, k);
    }
    else
    {
        // binary search in first graf line
        return binarysearch(arr, 0, pivot1, k);
    }
}
