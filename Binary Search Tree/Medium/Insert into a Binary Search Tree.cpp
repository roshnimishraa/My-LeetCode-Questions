TC : O(log N) base 2 
SC : O(H) 


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) 
            return new TreeNode(val);
  TreeNode *curr = root;      
        while(root != NULL){
            if(val >= curr->val){
                if(curr->right != NULL){
                    curr = curr->right;
                }
                else{
                curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left != NULL){
                    curr = curr->left;
                }
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
