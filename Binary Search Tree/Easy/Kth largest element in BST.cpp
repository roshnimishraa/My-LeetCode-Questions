Approach : Inorder Traversal 

Algorithm 
1. Inorder traversal give traversal in sorted order
2. store nodes in some vector
3. return arr[n-k] 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.

class Solution
{
    void inorder(Node *root,int k,vector<int> &ans)
    {
        if(root == NULL) return;
    inorder(root->left,k,ans);
    ans.push_back(root->data);
    inorder(root->right,k,ans);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        vector<int> ans;
     inorder(root,K,ans);
     int n=ans.size();
     return ans[n-K];
     
    }
};
