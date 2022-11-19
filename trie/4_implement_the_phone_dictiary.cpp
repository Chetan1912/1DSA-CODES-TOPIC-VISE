class trienode
{
public:
    char data;
    trienode *children[26];
    bool isTerminal;

    trienode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
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

    void insertutil(trienode *root, string word)
    {
        // base case

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        trienode *child;

        // present

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        // recursive call

        insertutil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertutil(root, word);
    }

    void printsuggestion(trienode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            trienode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printsuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str)
    {
        trienode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastchar = str[i];
            prefix.push_back(lastchar);

            // check for last char
            trienode *curr = prev->children[lastchar - 'a'];

            // if not found

            if (curr == NULL)
            {
                break;
            }

            // if found
            vector<string> temp;
            printsuggestion(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();

            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // creation of trie
    trie *t = new trie();

    // inseert all contact in trie

    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertword(str);
    }

    // return ans
    return t->getSuggestion(queryStr);
}