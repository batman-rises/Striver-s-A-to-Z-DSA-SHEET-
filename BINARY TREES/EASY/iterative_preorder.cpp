vector<int> preorder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();

        ans.push_back(curr->data);

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
    return ans;
}