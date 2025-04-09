int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;

    int ans = 0;
    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        unsigned long long minm = q.front().second;
        unsigned long long first, last;

        for (int i = 0; i < size; i++)
        {
            unsigned long long cur_ind = q.front().second - minm;
            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0)
                first = cur_ind;
            if (i == size - 1)
                last = cur_ind;

            if (node->left)
                q.push({node->left, cur_ind * 2 + 1});
            if (node->right)
                q.push({node->right, cur_ind * 2 + 2});
        }

        ans = max(ans, (int)(last - first + 1));
    }

    return ans;
}
