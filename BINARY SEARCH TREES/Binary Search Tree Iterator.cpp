class BSTIterator {
public:
    stack<TreeNode*> st;

    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* x=st.top();
        st.pop();
        pushAll(x->right);
        //st.pop();
        return x->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
