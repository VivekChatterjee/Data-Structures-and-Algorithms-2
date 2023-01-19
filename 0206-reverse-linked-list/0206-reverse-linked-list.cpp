/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *rev=head, *prev=NULL, *ans=NULL;
        while(rev)
        {
            ListNode* nxt=rev->next;
            rev->next=prev;
            prev=rev;
            rev=nxt;
            if(nxt) ans=nxt;
        }
        return ans;
    }
};