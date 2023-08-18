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

Approach : 
1. When the two pointers meet, we know that there is a cycle in the linked list.
2. We then reset the slow pointer to the head of the linked list and move both pointers at the same pace, one step at a time, until they meet again.
3. The node where they meet is the starting point of the cycle.
4. If there is no cycle in the linked list, the algorithm will return null.
    
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



  
