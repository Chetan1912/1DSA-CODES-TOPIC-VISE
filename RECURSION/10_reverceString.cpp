#include <iostream>
using namespace std;
void reverce(string &str, int i, int j)
{
    if (i > j)
    {
        return;
    }

    swap(str[i], str[j]);
    i++;
    j--;
    reverce(str, i, j);
}
int main()
{
    string name = "CHETAN";
    reverce(name, 0, name.length() - 1);
    cout << name;
}