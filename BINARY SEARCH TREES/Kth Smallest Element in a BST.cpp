class Solution {
public:
    void inorder(TreeNode* root, int k,int &cnt,int &res){
        if(root==NULL || cnt>=k)return;
        inorder(root->left,k,cnt,res);
        cnt=cnt+1;
        if(cnt==k){
            res=root->val;
            return;
        }
        inorder(root->right,k,cnt,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int res=-1;
        inorder(root,k,cnt,res);
        return res;
    }
};