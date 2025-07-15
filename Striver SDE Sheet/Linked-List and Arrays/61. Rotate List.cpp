/*
We have to rotate a linked list by k, we started by first getting the last node , then we make the 
next of last node to head so that a cycle forms, then from that last node we go length-k forward
,this gives us the node which we have to break(means this will be the tail of the new list),so 
we make its next nullptr.
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k ==0) return head;

        ListNode* curr = head;
        int len = 1;
        while(curr->next != nullptr){
            curr = curr->next;
            len++;
        }

        curr->next = head;

        k = k % len;
        k = len-k;
        while(k--){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;

return head;
      
    }
};
