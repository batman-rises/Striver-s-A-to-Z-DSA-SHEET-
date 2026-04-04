class Solution {
  public:
    void inorder(Node* root,vector<Node*> &res){
        if(root==NULL)return;
        inorder(root->left,res);
        res.push_back(root);
        inorder(root->right,res);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(root==NULL)return {NULL};
        Node* pre=NULL;
        Node* suc=NULL;
        
        vector<Node*> res;
        inorder(root,res);
        
        for(int i=0;i<res.size();i++){
            if(res[i]->data < key){
                pre=res[i];
            }
            else if(res[i]->data > key){
                suc=res[i];
                break;
            }
        }
        // while(root){
        //     if(root->data < key){
        //         pre=root;
        //         root=root->right;
        //     }
        //     else if(root->data > key)
        //     {
        //         suc=root;
        //         root=root->left;
        //     }
        // }
        
        return {pre,suc};
    }
};