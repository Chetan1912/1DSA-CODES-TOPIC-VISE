// #approach 1 in note
// #approach 2

class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->col = col;
        this->row = row;
    }
};
class comp
{
public:
    bool operator()(node a, node b)
    {
        return a.data > b.data;
    }
};
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &arr)
    {
        int K = arr.size();
        priority_queue<node, vector<node>, comp> minheap;
        int mn = INT_MAX;
        int mx = INT_MIN;
        int range = INT_MAX;

        // step 1 store the first element;
        for (int i = 0; i < K; i++)
        {
            node d(arr[i][0], i, 0);
            minheap.push(d);
            mn = min(mn, arr[i][0]);
            mx = max(mx, arr[i][0]);
        }
        int start = mn;
        int end = mx;

        while (!minheap.empty())
        {
            node temp = minheap.top();
            minheap.pop();
            int maybemin = temp.data;
            int row = temp.row;
            int col = temp.col;

            if (range > mx - maybemin)
            {
                mn = maybemin;
                range = mx - mn;
                start = mn;
                end = mx;
            }

            if (col + 1 != arr[row].size())
            {
                node next(arr[row][col + 1], row, col + 1);
                minheap.push(next);
                mx = max(mx, next.data);
            }
            else
            {
                break;
            }
        }

        return {start, end};
    }
};

