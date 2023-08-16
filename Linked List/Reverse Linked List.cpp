Iterative Approach : 
TC :O(N) 
SC :O(1)

  class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        while(curr != NULL){
          next=curr->next;
           curr->next=prev;
           prev=curr;
            curr=next;
            
        }
        return prev;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------

  Recursive Approach : 
TC :O(N)
SC :O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
  if(head == NULL || head->next ==NULL){
      return head;
  }
        ListNode *rest_head=reverseList(head->next);
        ListNode *rest_tail = head->next;
        rest_tail->next=head;
    head->next = NULL;
        return rest_head;
    }
};
