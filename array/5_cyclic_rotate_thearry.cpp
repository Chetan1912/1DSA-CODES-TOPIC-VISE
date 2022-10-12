// } Driver Code Ends

// User function Template for C++

void rotate(int arr[], int n)
{
    int last = arr[n - 1];
    int j = n - 1;
    while (j > 0)
    {
        arr[j] = arr[j - 1];
        j--;
    }
    arr[0] = last;
}