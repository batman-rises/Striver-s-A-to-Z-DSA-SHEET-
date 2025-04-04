void preorder(node)
{
    if (node == NULL)
        return;

    print(node->data);
    preorder(node->left);
    preorder(node->right);
}