Approach 1: Naive approach (Not Optimised)

Intuition + Approach:

For a Balanced Binary Tree, Check left subtree height and right subtree height for every node present in the tree. Hence, traverse the tree recursively and calculate the height of left and right subtree from every node, and whenever the condition of Balanced tree violates, simply return false.
Condition for Balanced Binary Tree
For all Nodes , Absolute( Left Subtree Height – Right Subtree Height ) <= 1

~Time Complexity: O(N*N)
Reason: ( For every node, Height Function is called which takes O(N) Time. Hence for every node it becomes N*N )
~Space Complexity: O(1) ( Extra Space ) + O(H)
Reason: ( Recursive Stack Space where “H” is the height of tree )

------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 2: Post Order Traversal ( Most optimised )

Intuition: 
1. Yes, so can we skip the repeated traversals?
2. What if we can make use of post-order traversal?
3. So, the idea is to use post-order traversal. Since, in postorder traversal, we first traverse the left and right subtrees and then visit the parent node, similarly instead of calculating the height of the left subtree and right subtree every time at the root node, use post-order traversal, and keep calculating the heights of the left and right subtrees and perform the validation.

Approach :

1. Start traversing the tree recursively and do work in Post Order.
2. For each call, caculate the height of the root node, and return it to previous calls.
3. Simultaneously, in the Post Order of every node , Check for condition of balance as information of left and right subtree height is available.
4. If it is balanced , simply return height of current node and if not then return -1.
5. Whenever the subtree result is -1 , simply keep on returning -1.

~Time Complexity: O(N)
~Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H” is the height of binary tree)

if it is balanced return height of the tree 
if it is not balanced return -1 


//recursive approach 

class Solution {
    int height(TreeNode *root){
        if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
        
 // if after calculating height the difference of either in left and right // subtree is greater than 1 return -1
        
        if(left == -1 || right == -1) return -1;
//if tree is balanced return max height and if it is not balanced return -1
    if(abs(left-right) > 1) return -1;

    return max(left,right)+1;
        
    }
public:
    bool isBalanced(TreeNode* root) {
      if(root == NULL ) return true;
        if(height(root) == -1) return false;
        
        return true;
        
    }
};
