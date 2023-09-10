Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST)


class Solution
{
    public:
        Node* insert(Node* node, int data) {
        
if(node == NULL) 
{
    return new Node(data);
}

if(node->data < data ){
    node->right = insert(node->right,data);
}

else if(node->data > data){
  node->left=insert(node->left,data);
}
return node;
    }

};
