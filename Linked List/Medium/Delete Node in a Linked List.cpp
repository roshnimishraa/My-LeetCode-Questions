Approach: 
Basically we are just copying node's next value to itself
Input: 1->2->3->4->5 ->6
given node = 4
output: 1->2->3->5->6

1. in first step: node->val becomes node's next ki value i.e 4 becomes 5
1->2->3->5->5->6
2. in 2nd step: node points to node's next next i.e 5->6
1->2->3->5->6

  TC : O(1) 
  SC : O(1) 
  
  void deleteNode(ListNode* node) {
        ListNode *curr = node;
        //copy val 
        curr->val = curr->next->val;
        //deleting node 
        curr->next = curr->next->next;
    }
