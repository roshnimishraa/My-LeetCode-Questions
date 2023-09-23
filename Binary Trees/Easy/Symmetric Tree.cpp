For Symmetric 
root->left          root->right
Root Left Right     Root Right Left 

Time Complexity: O(N)
Reason: We are doing simple tree traversal and changing both root1 and root2 simultaneously.
Space Complexity: O(N)
Reason: In the worst case (skewed tree), space complexity can be O(N).

class Solution {
    bool helper(TreeNode* left,TreeNode* right)
    {

    if(left == NULL || right == NULL) return left == right;
        
    if(left->val != right->val) return false;
        
    return helper(left->left,right->right) && helper(left->right,right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || helper(root->left,root->right) )
            return true;
        else 
            return false;
    }
};
