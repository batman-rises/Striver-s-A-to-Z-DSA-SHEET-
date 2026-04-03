class Solution {
  public:
    int minValue(Node* root) {
        // code here
        while(root->left){
            root=root->left;
        }
        return root->data;
    }
};