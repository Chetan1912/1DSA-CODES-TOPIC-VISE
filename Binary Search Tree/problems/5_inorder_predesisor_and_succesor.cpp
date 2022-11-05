#include <iostream>
using namespace std;
pair<int, int> preandsuc(node *root, int key)
{
    int pre = -1;
    int suc = -1;
    node *temp = root;
    while (temp->> data != key)
    {
        if (temp->data > key)
        {
            suc = temp->data;
            temp = temp->left;
        }
        else
        {
            pre = temp->data;
            temp = temp->right;
        }
    }
    // pred and succ
    // pred
    node *left = temp->left;
    while (left != NULL)
    {
        pre = left->data;
        left = left->right;
    }

    // succ
    node *right = temp->left;
    while (right != NULL)
    {
        suc = right->data;
        left = right->left;
    }
    return {pre, suc};
}
