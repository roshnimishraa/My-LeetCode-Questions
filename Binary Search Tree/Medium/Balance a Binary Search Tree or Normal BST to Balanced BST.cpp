Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
  N -> Number of nodes 

class Solution {
    private:
    void inorder(TreeNode *root,vector<TreeNode*> &ans)
    {
        if(root == NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root);
        inorder(root->right,ans);
    }
    TreeNode *buildTree(int start,int end,vector<TreeNode*> &ans)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode *root = ans[mid];
        root -> left = buildTree(start,mid-1,ans);
        root-> right =buildTree(mid+1,end,ans);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
    if(root == NULL) {
        return root;
    }
    vector<TreeNode*> ans;
 inorder(root,ans);
        int n = ans.size();
    return buildTree(0,n-1,ans);
    }
};
