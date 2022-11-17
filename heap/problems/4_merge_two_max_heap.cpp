class Solution
{
public
    int[] mergeHeaps(int[] a, int[] b, int n, int m)
    {

        int merged[] = new int[m + n];

        for (int i = 0; i < n; i++)
        {
            merged[i] = a[i];
        }

        for (int i = 0; i < m; i++)
        {
            merged[i + n] = b[i];
        }

        int k = m + n;

        for (int i = (k / 2) - 1; i >= 0; i--)
        {

            maxHeapify(merged, k, i);
        }

        return merged;
    }

private
    void Heapify(int arr[], int n, int i)
    {

        if (i >= n)
            return;

        int parent = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[parent])
        {

            parent = l;
        }

        if (r < n && arr[r] > arr[parent])
        {

            parent = r;
        }

        if (parent != i)
        {

            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            Heapify(arr, n, parent);
        }
    }
}