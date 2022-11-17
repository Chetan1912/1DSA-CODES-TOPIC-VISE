k th largest;

public:
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums)
    {
        pq.push(num);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
}
;
k th smalest;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        priority_queue<int> ele;
        for (int i = l; i <= r; i++)
        {
            ele.push(arr[i]);
            if (ele.size() > k)
                ele.pop();
        }
        return ele.top();
    }
};