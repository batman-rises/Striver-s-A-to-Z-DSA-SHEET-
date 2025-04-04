void create_tree(node *root, vector<int> &vec)
{
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && vec.size() < 7)
    {
        Node *curr = q.front();
        q.pop();

        if (i < vec.size() && vec[i] != -1)
        {
            curr->left = new Node(vec[i]);
            q.push(curr->left);
        }
        i++;
        if (i < vec.size() && vec[i] != -1)
        {
            curr->right = new Node(vec[i]);
            q.push(curr->right);
        }
        i++;
    }
}