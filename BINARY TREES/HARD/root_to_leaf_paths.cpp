class Solution
{
public:
    void findpaths(Node *root, vector<int> &path, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        path.push_back(root->data);

        if (!root->left && !root->right)
        {
            ans.push_back(path);
        }
        else
        {
            findpaths(root->left, path, ans);
            findpaths(root->right, path, ans);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> path;
        findpaths(root, path, ans);
        return ans;
    }
};
