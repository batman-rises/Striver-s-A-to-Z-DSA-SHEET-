class Solution
{
public:
    void func(TreeNode *root, int &c)
    {
        if (root == NULL)
            return;

        func(root->left, c);
        c++;
        func(root->right, c);
    }
    int countNodes(TreeNode *root)
    {
        int cnt = 0;
        func(root, cnt);
        return cnt;
    }
};