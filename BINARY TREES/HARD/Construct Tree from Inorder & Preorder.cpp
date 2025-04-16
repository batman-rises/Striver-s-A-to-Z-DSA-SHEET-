class Solution
{
public:
    // Function to build the tree from given inorder and preorder traversals
    Node *solve(vector<int> &preorder, vector<int> &inorder, int &i, int s, int e, unordered_map<int, int> &mp)
    {
        if (s > e)
            return NULL;
        int rootVal = preorder[i++];
        Node *root = new Node(rootVal);

        int in = mp[rootVal];
        root->left = solve(preorder, inorder, i, s, in - 1, mp);
        root->right = solve(preorder, inorder, i, in + 1, e, mp);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = inorder.size();
        int preI = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, preI, 0, n - 1, mp);
    }
};