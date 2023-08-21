Time Complexity: O(N).
Reason: We are doing a tree traversal.
Space Complexity: O(N)
Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
     if(p==NULL || q == NULL)
         return (p==q);
        
     return (p->val == q->val)
         && isSameTree(p->left,q->left)
         && isSameTree(p->right,q->right);
        
    }
};
