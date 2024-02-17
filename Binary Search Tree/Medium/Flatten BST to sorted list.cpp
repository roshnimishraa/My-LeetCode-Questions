//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    Node *flattenBST(Node *root)
    {
    if(root == NULL) return root;
    Node *head = flattenBST(root->left);
    root->left = NULL;
    root->right = flattenBST(root->right);
    Node *temp = head;
    while(temp != NULL && temp->right!=NULL)
    {
        temp = temp->right;
    }
if(head !=NULL)
{
    temp->right = root;
}
else{
    head = root;
}
    return head;
    }
};v
