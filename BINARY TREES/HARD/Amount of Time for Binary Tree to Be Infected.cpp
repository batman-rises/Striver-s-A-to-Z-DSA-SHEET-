class Solution
{
public:
    TreeNode *bfsToMapParents(TreeNode *root, map<TreeNode *, TreeNode *> &mpp, int start)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res;

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            if (cur->val == start)
                res = cur;

            if (cur->left)
            {
                mpp[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right)
            {
                mpp[cur->right] = cur;
                q.push(cur->right);
            }
        }
        return res;
    }
    int maxTime(map<TreeNode *, TreeNode *> mpp, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(target);
        map<TreeNode *, int> vis;
        vis[target] = 1;
        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            int fl = 0;
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left])
                {
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right])
                {
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if (mpp[node] && !vis[mpp[node]])
                {
                    fl = 1;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            if (fl)
                time++;
        }
        return time;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        map<TreeNode *, TreeNode *> mpp;
        TreeNode *target = bfsToMapParents(root, mpp, start);
        return maxTime(mpp, target);
    }
};