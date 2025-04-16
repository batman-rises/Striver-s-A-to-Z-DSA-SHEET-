class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        while (root)
        {
            if (root->left == NULL)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                TreeNode *cur = root->left;
                while (cur->right && cur->right != root)
                {
                    cur = cur->right;
                }
                // not tarversed
                if (cur->right == NULL)
                {
                    cur->right = root;
                    root = root->left;
                }
                // already traversed
                else
                {
                    ans.push_back(root->val);
                    cur->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};