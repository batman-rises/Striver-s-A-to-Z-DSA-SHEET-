vector<int> inorder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node *> st;
    Node *node = root;

    while (true))
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;

                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
    return ans;
}