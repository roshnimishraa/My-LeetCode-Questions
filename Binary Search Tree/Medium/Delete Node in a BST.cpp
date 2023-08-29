
Time Complexity: O(h), where h is the height of the BST. 
Auxiliary Space: O(n).

class Solution {
public:
    int MaxLeft(TreeNode* root)
    {
while(root->right!=nullptr)
        {
            root=root->right;

        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(root->val == key){
            // 0 Child
            if(root->left == NULL && root->right == NULL){
              delete root;
              return NULL;
            }
// 1 Child
if(root->left != NULL && root->right == NULL)
{
  TreeNode* temp= root->left;

  return temp;
}
if(root->left == NULL && root->right != NULL){
    TreeNode* temp = root->right;

    return temp ;
}
// 2 Child
if(root->left != NULL && root->right != NULL){
    int leftmax= MaxLeft(root->left);
 root->val=leftmax;
   root->left=deleteNode(root->left,leftmax);
    return root;
}
}
else if(root->val >key){
    root->left = deleteNode(root->left,key);

}
else if(root->val < key){
    root->right = deleteNode(root->right,key);

}


else{
    root->right = deleteNode(root->right,key);
}

return root;
    }
};
