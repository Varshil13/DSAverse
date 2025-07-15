/*
We have to find if a ll is palindrome or not, we can do this with multiple ways , one is a simple
soluton that is create a array form the ll and them check if that array is palindrome or not, in this
solution tc is o(n) but there is space complexity of o(n).

Other solutons has space complexity of o(1), we get the middle of the ll using fast and slow pointer,
then we reverse the ll after the slow->next, then me move slow pointer to next and then we start comparing
head and slow , if both same then we move next , if not then we return false.

 */
class Solution {
    ListNode* reversell(ListNode* head){
        ListNode* h = head;
        ListNode* pre= nullptr;
        while(h != nullptr){
            ListNode* temp = h->next;
            h->next = pre;
            pre = h;
            h = temp;
        }
        return pre;

    }
public:
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!= nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reversell(slow->next);

        slow = slow->next;

        while(slow!=nullptr){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        
        }
        return true;


    }
};

