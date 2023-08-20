// Preorder

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> preorder;
        stack<TreeNode*> stack;
        if (root == NULL)
            return preorder;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            preorder.push_back(curr->val);
            if (curr->right != NULL)
                stack.push(curr->right);
            if (curr->left != NULL)
                stack.push(curr->left);
        }
        return preorder;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Inorder
Time Complexity: O(N).
Reason: We are traversing N nodes and every node is visited exactly once.
Space Complexity: O(N)
Reason: In the worst case (a tree with just left children), the space complexity will be O(N).
    
Approach : 

1. We first take an explicit stack data structure and set an infinite loop.
2. In every iteration we check whether our current node is pointing to NULL or not.
3. If it is not pointing to null, we simply push the current value to the stack and move the current node to its left child.
4. If it is pointing to NULL, we first check whether the stack is empty or not. If the stack is empty, it means that we have traversed 
the tree and we break out of the loop.
5. If the stack is not empty, we pop the top value of the stack, print it and move the current node to its right child.
    
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
    
    	// 1. Make root as the starting node, that is currNode
        TreeNode *currNode = root;
        
    while(currNode or !st.empty()){
	// 2. Now add all the left subtree nodes to the stack
        while(currNode){
            st.push(currNode);
            currNode = currNode->left;
        }
    
// 3. Pick out the top node, put it in answer array
        currNode = st.top();
        st.pop();
        
        ans.push_back(currNode->val);
        
// 4. Update currNode as below, this will take care of the right subtree
    currNode = currNode->right;
    }
        return ans;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    
// Postorder : Using 2 stacks

Time Complexity: O(N).
Reason: We are traversing N nodes and every node is visited exactly once.
Space Complexity: O(N+N)
    
Approach :
1. We take two explicit stacks S1 and S2.
2. We insert our node to S1(if it’s not pointing to NULL).
3. We will set up a while loop to run till S1 is non-empty.
4. In every iteration, we pop out the top of S1 and then push this popped node to S2. Moreover we will push the left child and right child of this popped node to S1.(If they are not pointing to NULL).
5. Then we start the next iteration with the next node as top of S1.
6. We stop the iteration when S1 becomes empty.
7. At last we start popping at the top of S2 and print the node values, we will get the postorder traversal.
    
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st1,st2;
        if(root == NULL) return {};
        
//push root
        st1.push(root);
        
    //push ele in st1
while(!st1.empty())
{
  root = st1.top();
    st1.pop();
    
    //push root in str2
    
    st2.push(root);
    
 if(root->left != NULL) 
     st1.push(root->left);
    
if(root->right != NULL) 
    st1.push(root->right);
}
        
while(!st2.empty())
{
    //store ans in vector from st2 and pop from st2
   ans.push_back(st2.top()->val);
    st2.pop();
    
}
        return ans;
    }
};


// Postorder Traversal using 1 stack 


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == NULL) return ans;
        
    st.push(root);
        while(!st.empty()){
 
            TreeNode *curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            
 if(curr->left != NULL)
            st.push(curr->left);
      
    if(curr->right != NULL)
        st.push(curr->right);           
 }
      reverse(ans.begin(),ans.end());
        return ans;
    }          
};



