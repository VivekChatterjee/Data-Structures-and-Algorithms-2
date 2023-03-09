class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* slow=head, *fast=head;
        do
        {
            slow=slow->next;
            fast=fast->next->next;
            if(!fast || !fast->next) return NULL;
        }while(fast && fast->next && fast!=slow);
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};