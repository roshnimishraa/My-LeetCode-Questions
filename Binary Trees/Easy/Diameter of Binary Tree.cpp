Time Complexity: O(N) 
Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree )  


class Solution {
    int  height(TreeNode *root,int &diameter){
        if(root == NULL ) return 0;
        int lh = height(root->left,diameter);
        int rh = height(root->right, diameter);
        
        diameter = max(diameter,lh+rh);
        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
        
    }
};
