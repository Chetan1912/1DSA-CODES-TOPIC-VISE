#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void deleteheapnode()
    {
        if (size == 0)
        {
            cout << "kya delete kareg re baba yha to sab khli pdda h\n";
            return;
        }
        // for gandle the if there are two node only
        if (size < 4)
        {
            int i = 1;
            arr[1] = max(arr[i + 1], arr[i + 2]);
            arr[2] = min(arr[i + 1], arr[i + 2]);
            size--;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftchild = 2 * i;
            int rightchild = (2 * i) + 1;
            if (leftchild < size && arr[i] < arr[leftchild] && arr[leftchild] > arr[rightchild])
            {
                swap(arr[i], arr[leftchild]);
                i = leftchild;
            }
            else if (rightchild < size && arr[i] < arr[rightchild] && arr[rightchild] > arr[leftchild])
            {
                swap(arr[i], arr[rightchild]);
                i = rightchild;
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(100);
    h.insert(25);
    h.insert(101);
    h.insert(500);
    h.insert(250);
    h.insert(5055);

    h.print();
    printf("\n");

    h.deleteheapnode();
    h.print();

    h.deleteheapnode();
    printf("\n");
    h.print();
    h.deleteheapnode();
    printf("\n");
    h.print();
    h.deleteheapnode();
    printf("\n");
    h.print();
    h.deleteheapnode();
    printf("\n");
    h.print();
    h.deleteheapnode();
    printf("\n");
    h.print();
    h.deleteheapnode();
    printf("\n");
    h.print();
    h.deleteheapnode();
    printf("\n");
    h.print();
}
