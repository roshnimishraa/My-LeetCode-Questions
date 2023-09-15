TC : O(N) 
SC : O(N) 

Approach : 
1. Do Inorder Traversal 
2. return k-1 index 

class Solution {
    void inorder(TreeNode* root,vector<int> &ans)
    {
        if(root == NULL) return;
    
inorder(root->left,ans);
ans.push_back(root->val);
inorder(root->right,ans);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
    inorder(root,ans);
return ans[k-1];
    }
};
