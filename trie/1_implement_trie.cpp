#include <iostream>
using namespace std;
class trienode
{
public:
    char data;
    trienode *children[26];
    bool isterminal;
    trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class trie
{
public:
    trienode *root;
    trie()
    {
        root = new trienode('\0');
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////insertion/////////////////////////////////////////////////////////////////////////////////////////////////////////
    void insertutil(trienode *root, string word)
    {
        // BASE CASE
        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        // assume the word is in capita letter
        int index = word[0] - 'A';
        trienode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absant
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }
        // recursion ji
        insertutil(child, word.substr(1));
    }
    void insertword(string word)
    {
        insertutil(root, word);
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////search/////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool searchutil(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isterminal;
        }
        int index = word[0] - 'A';
        trienode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        { // sbsent
            return false;
        }
        return searchutil(child, word.substr(1));
    }
    bool searchinstring(string word)
    {
        return searchutil(root, word);
    }
    void removeutil(trienode *root, string word)
    {
        if (searchinstring(word))
        {
        }
        else
        {
            cout << "WORD IS NOT PRESENT SO IT IS ALREADY DELETED\n";
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////empty/////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool isEmpty(trienode *root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return false;
        return true;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////deletionx/////////////////////////////////////////////////////////////////////////////////////////////////////////
    void removestring(string word)
    {
        removeutil(root, word);
    }
};
int main()
{
    trie *t = new trie();
    t->insertword("HI");
    cout << t->searchinstring("HI");
}