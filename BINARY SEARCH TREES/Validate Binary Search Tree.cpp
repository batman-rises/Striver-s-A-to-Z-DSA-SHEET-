class Solution {
public:
    bool helper(TreeNode* root, long &prev){
        if(root == NULL) return true;

        if(!helper(root->left, prev)) return false;

        if(root->val <= prev) return false;

        prev = root->val;

        return helper(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return helper(root, prev);
    }
};