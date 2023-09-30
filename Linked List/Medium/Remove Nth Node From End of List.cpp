TC : O(N) 
SC : O(1) 
ALGORITHM : TWO POINTER APPROACH 
1. Initialize dummy node and make dummy -> next = head
2. Initialize slow and fast pointer initially pointing to dummy node
3. Move fast pointer till n by one step
4. Then until fast->next != NULL 
  Move slow and fast pointer by one 
5. The nodeToBeDeleted is slow->next remove link
6. Return dummy->next
  
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        
        //traverse fast pointer till n 
    for(int i=1;i<=n;i++){
        fast = fast->next;
    }
//   now move fast and slow pointer by 1 till fast->next != NULL
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
//    remove link of slow -> next or nodeToBeDeleted 
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
