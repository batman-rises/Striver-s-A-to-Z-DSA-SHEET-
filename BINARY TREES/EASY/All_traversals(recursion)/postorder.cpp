void postorder(node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    print(node->data);
}