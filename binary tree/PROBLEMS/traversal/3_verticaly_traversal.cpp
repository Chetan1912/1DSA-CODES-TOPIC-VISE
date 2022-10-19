ector<vector<int>> verticalTraversal(TreeNode *root)
{

    vector<vector<int>> res;
    if (!root)
        return res;

    map<int, map<int, vector<int>>> mp; // horizontalDist, level, node->data

    queue<pair<TreeNode *, pair<int, int>>> q; // node, horizontalDist, level

    q.push({root, {0, 0}}); // node, hd, lvl

    while (!q.empty())
    {

        auto f = q.front();
        q.pop();

        TreeNode *curr = f.first;  // curr node
        int hd = f.second.first;   // hd of curr node
        int lvl = f.second.second; // lvl of curr node

        mp[hd][lvl].push_back(curr->val); // pushing in map

        if (curr->left)
            q.push({curr->left, {hd - 1, lvl + 1}}); // check if curr->left exists or not
        if (curr->right)
            q.push({curr->right, {hd + 1, lvl + 1}}); // check if curr->right exists or not
    }

    // Retrieving Vertical Traversal
    for (auto i : mp)
    {
        vector<int> ans;
        for (auto j : i.second)
        {
            sort(j.second.begin(), j.second.end());
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
        res.push_back(ans);
    }

    return res;
}