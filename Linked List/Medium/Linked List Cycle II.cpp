Statement : if ele exists return index if not exists return null

Brute force : Hashing(unorder_set)
Approach : store num in hash table if it again come return true

Time complexity: O(N)
Space complexity: O(N)


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st; //storing address 
        ListNode *curr = head;
        while(curr != NULL){
            // if element exist 
            if(st.find(curr) != st.end()){
                return curr;
            }
            else{
                st.insert(curr);
                curr = curr->next;
            }
        }
        return NULL;
    }
};    
----------------------------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Two - Pointer Approach (slow & fast pointer)

 TC : O(N)
 SC : O(1) 


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast =head;
        ListNode *slow =head;
        while(fast != NULL && fast ->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
            slow =head;
                while(slow != fast){
                    slow = slow ->next;
                    fast = fast->next;
                }
                   return slow;
            }
         
        }
        
      //if cycle not exist 
        return NULL;
    }
};



  
