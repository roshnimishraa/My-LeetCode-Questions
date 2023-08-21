Naive Approach : 
Approach: A brute force approach would be to generate all paths and compare them.
Generating all paths will be a time-costly activity therefore we need to look for something else.

  TC : O(N)^2
  

---------------------------------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : 
1. Initialize a maxi variable to store our final answer.
2. Do a simple tree traversal. At each node, find  recursively its leftMaxPath and its rightMaxPath.
3. Calculate the maxPath through the node as val + (leftMaxPath + rightMaxPath) and update maxi accordingly.
4. Return the maxPath when node is not the curving point as val + max(leftMaxPath, rightMaxPath).

Time Complexity: O(N)
Reason: We are doing a tree traversal
Space Complexity: O(N)
Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N)


//Recursive approach : 
class Solution {
    int maxPathDown(TreeNode *root,int &maxi)
    {
        if(root == NULL) return 0;

//if -ve path sum get from left and right make it 0 
        int left = max(0,maxPathDown(root->left,maxi));
        int right = max(0,maxPathDown(root->right,maxi));
        
        maxi= max(maxi,left+right+root->val);
    return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
    }
};
