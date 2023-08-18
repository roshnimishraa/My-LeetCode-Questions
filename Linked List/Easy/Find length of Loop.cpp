Approach : 
1. if slow == fast meet then 
2. move slow by one and do count++ until slow != fast

    Time complexity: O(n)
    Space complexity: O(1)

int lengthOfLoop(Node *head) {
    Node *fast =head;
    Node *slow=head;
    
 while(fast != NULL && fast->next != NULL){
     slow = slow->next;
     fast = fast->next->next;
      
      if(fast == slow) {
          int count =1;
          slow = slow->next;
          while(slow != fast){
              count++;
              slow = slow->next;
          }
          return count;
      }
  }
  //no loop 
  return 0;
}
