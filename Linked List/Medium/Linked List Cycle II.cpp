Statement : if ele exists return index if not exists return null

Brute force : Hashing 
Approach : store num in hash table if it again come return true

Time complexity: O(N)
Space complexity: O(N)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
//         brute force
        int i=0;
    unordered_map<ListNode*,int> umap;
        ListNode *temp =head;
        while(temp != NULL){
    //if element exists
            if(umap.find(temp) != umap.end()){
                return temp; 
            }
            umap[temp] =i++;
            temp=temp->next;
        }
        return NULL;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Two - Pointer Approach (slow & fast pointer)

 TC : O(N)
 SC : O(1) 






  
