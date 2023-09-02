statement 
Given a binary tree and a budget. Assume you are at the root of the tree(level 1), 
  you need to maximise the count of leaf nodes you can visit in your budget if the cost of visiting a leaf node is equal to the level of that leaf node.

Input: 
                  10
                /    \
               8      2
             /      /   \
            3      3     6
                    \
                     4
and budget = 8
Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
In budget 8 one can visit Max 2 Leaf Nodes.
  
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


**********************************IMPLEMENTATION**************************************************************************************************************
  
int getCount(Node *root, int k)
    {
    queue<pair<Node*,int>> q;
    q.push({root,1});
    
int count=0;
int sum=0;

while(q.size()>0)
{
    auto node = q.front().first;
    int level = q.front().second;
    q.pop();
    
    // left node
    if(node->left == NULL && node->right == NULL){
       count++;
       sum = sum+level;
       
      if(sum > k) return count-1;
      if(sum == k) return count;
    }
// left and right subtree
if(node->left != NULL) 
q.push({node->left,level+1});

if(node->right != NULL) 
q.push({node->right,level+1});

}
return count;
    }
