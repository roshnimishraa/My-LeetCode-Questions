Approach : Reverse Preorder + Recursion 
  TC : O(N) 
   SC : O(H)
  Root Right Left 
1. if(root == NULL) return 
2. store the right side view in ds ans 
     ans.size() == level then store node
3. recursive call for right subtree with level+1
4. recursive call for left subtree with level+1
5. return ans 

class Solution {
    void helper(TreeNode* root,int level,vector<int> &ans)
    {
 if(root == NULL) return;
        
if(ans.size() == level) ans.push_back(root->val);
helper(root->right,level+1,ans);
helper(root->left,level+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root,0,ans);
        return ans;
    }
};
