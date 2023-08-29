
Time Complexity: O(h), where h is the height of the BST. 
Auxiliary Space: O(n).


    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private : 
    int maxLeft(TreeNode* root)
    {

        while(root != NULL && root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root == NULL){
            return root;
        }

if(root->val == key)
    {
// 1. leaf node
if(root->left == NULL && root->right == NULL){
    delete root;
    return NULL;
}

// 1 child 
if(root->left != NULL && root->right == NULL)
{
TreeNode *temp = root->left;
delete root;
 return temp;
}
if(root->left == NULL && root->right != NULL){
TreeNode *temp = root->right;
delete root;
 return temp;
}

// 2 child
if(root->left != NULL && root->right != NULL){
int maxi = maxLeft(root->left);
root->val = maxi;
root->left = deleteNode(root->left,maxi);
return root;
}
    }

// search function 
else if(root->val > key){
root->left = deleteNode(root->left,key);
}
else if(root->val < key){
 root->right = deleteNode(root->right,key);
}

return root;
    }
};
