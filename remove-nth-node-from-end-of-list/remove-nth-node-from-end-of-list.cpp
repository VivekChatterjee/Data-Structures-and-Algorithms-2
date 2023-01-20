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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        ListNode* start=head;
        int ct=0;
        while(start)
        {
            start=start->next;
            ct++;
        }
        if(n == ct) return head->next;
        int del=ct-n;
        int i=1;
        start=head;
        while(true)
        {
            if(i==del)
            {
                start->next=start->next->next;
                break;
            }
            start=start->next;
            i++;
        }
        return head;
    }
};