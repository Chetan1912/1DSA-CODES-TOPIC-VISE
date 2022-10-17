class solution
{
public:
    bool isident(node *r1, node *r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if (r1 == NULL && r2 != NULL)
        {
            return false;
        }
        if (r1 != NULL && r2 == NULL)
        {
            return false;
        }
        bool left = isident(r1->left, r2->left);
        bool right = isident(r1->right, r2->right);
        bool currval = r1->data == r2->data;

        if (left && right && currval)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};