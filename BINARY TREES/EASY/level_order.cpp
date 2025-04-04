class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        // Your code here
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                level.push_back(curr->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
