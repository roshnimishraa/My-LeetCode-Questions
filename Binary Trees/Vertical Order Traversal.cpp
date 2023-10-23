The vertical order traversal of a binary tree is a list of top-to-bottom 
orderings for each column index starting from the leftmost column and ending on the rightmost column. 

Approach : 
1. Take a queue store (node,vertical, level) 
 vertical -> start from root to left to right -> 0 to -1 to 1 ....
2. Take a map to store levels and multinodes with same value 
    map<int,map<int,multiset<int>>> mp -> store (vertical,(levels,multinodes with duplicate values in sorted order))

/*

Time Complexity: O(N*logN*logN*logN)

Space Complexity: O(N)
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
  TreeNode* frontNode = it.first;
int hd = it.second.first;
int level = it.second.second;
            
// insert  (horizontal distance,{level,node}) into map
//eg. [0][0]-> 1 root node val 1
    nodes[hd][level].insert(frontNode->val);
           
// traverse left 
if(frontNode->left != NULL)
{
    //push ({node,{horizontal Dist,level}) into queue
    q.push({frontNode->left,{hd-1,level+1}});
}
if(frontNode->right != NULL)
{
    q.push({frontNode->right,{hd+1,level+1}});
    
}
 }
vector<vector<int>> ans;
// take ans from map
     for(auto map_ele : nodes){
    //map_ele -> stores ({hd,{level,sorted nodes }})
         //hd -> map_ele.first
         //sorted nodes -> map_ele.second
    //take out sorted nodes
         vector<int> col;
        for(auto j : map_ele.second){
//j -> sorted nodes
//push into col vector
    col.insert(col.end(),j.second.begin(),j.second.end());
            
        }
         
ans.push_back(col);
     }   
        return ans;
    }
};
