// this is not the actual code runned see in leet code problem no 852
class solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int s = 0, e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s; // can return e   also    because both are same
    }
}