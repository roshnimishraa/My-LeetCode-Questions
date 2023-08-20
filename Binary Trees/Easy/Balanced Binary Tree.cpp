TC : O(N)
SC : O(N) 

Approach : 
1. Start traversing the tree recursively and do work in Post Order.
2. For each call, caculate the height of the root node, and return it to previous calls.  
3. Simultaneously, in the Post Order of every node , Check for condition of balance as information of left and right subtree height is available.
4. If it is balanced , simply return height of current node and if not then return -1.
5. Whenever the subtree result is -1 , simply keep on returning -1.

//recursive approach 
class Solution {
    int dfsHeight(TreeNode *root){
        if(root == NULL) return 0;
        
        int left = dfsHeight(root->left);
        int right = dfsHeight(root->right);
         
    if(left == -1 || right == -1) {
        return -1;
    }
        
        if(abs(right-left) > 1) return -1;
    return max(left,right) +1;
    }
public:
    bool isBalanced(TreeNode* root) {
     return dfsHeight(root) != -1;   
    }
};
