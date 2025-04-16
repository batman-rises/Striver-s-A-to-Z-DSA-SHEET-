class Solution
{
public:
    // Function to return a tree created from postorder and inoreder traversals.
    Node *solve(vector<int> &inorder, int inStart, int inEnd,
                vector<int> &postorder, int postStart, int postEnd, map<int, int> &mp)
    {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;

        Node *root = new Node(postorder[postEnd]);
        int in_root = mp[root->data];
        int numsLeft = in_root - inStart;

        root->left = solve(inorder, inStart, in_root - 1, postorder, postStart, postStart + numsLeft - 1, mp);
        root->right = solve(inorder, in_root + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, mp);

        return root;
    }
    Node *buildTree(vector<int> inorder, vector<int> postorder)
    {
        // code here
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        Node *root = solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1,
                           mp);
        return root;
    }
};
