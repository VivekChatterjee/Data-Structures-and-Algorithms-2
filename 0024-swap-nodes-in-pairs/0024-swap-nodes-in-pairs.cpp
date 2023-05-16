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
    ListNode* swap(ListNode *&head)
    {
        if(!head || !head->next)   return head;
        ListNode* temp=head->next;
        head->next=swap(temp->next);
        temp->next=head;
        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=swap(head);
        return temp;
    }
};