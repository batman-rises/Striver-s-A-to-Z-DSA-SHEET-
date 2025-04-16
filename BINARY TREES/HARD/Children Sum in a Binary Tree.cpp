class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        // Add your code here
        if (!root || (!root->left && !root->right))
            return 1;

        int left_val = (root->left) ? root->left->data : 0;
        int right_val = (root->right) ? root->right->data : 0;

        if (root->data == (left_val + right_val) &&
            isSumProperty(root->left) &&
            isSumProperty(root->right))
        {
            return 1;
        }

        return 0;
    }
};
