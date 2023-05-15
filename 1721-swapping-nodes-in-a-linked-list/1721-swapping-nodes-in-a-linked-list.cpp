class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ans=head;
        int cur=k-1;
        while(cur--) head=head->next;
        ListNode* first=ans;
        ListNode* second=head->next;
        ListNode*f = head;
        while(second)
        {
            first=first->next;
            second=second->next;
        }
        ListNode*s = first;
        swap(f->val, s->val);
        return ans;
    }
};