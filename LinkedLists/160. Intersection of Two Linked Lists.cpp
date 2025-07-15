/*
We have to find the intersection of 2 linked list , so we used 2 pointer approach , just the catch 
is that , if we traversed one ll and and reach nullptr while other ll is still being traversed then we 
point the first iterating pointer to the other ll's head, if they will meet at some node then thats the 
intersection otherwise they both will become nullptr.
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* a = headA;
        ListNode* b = headB;

        while(a !=  b){
            if(a == nullptr){
                a = headB;
            }
            else{
                a = a->next;
            }
            if(b == nullptr){
                b = headA;
            }
            else{
                b = b->next;
            }
            

        }

return a;
    }
};