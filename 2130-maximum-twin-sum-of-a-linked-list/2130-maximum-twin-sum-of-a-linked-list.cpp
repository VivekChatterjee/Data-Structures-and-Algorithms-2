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
    int pairSum(ListNode* head) {
        stack<int>s;
        int len=0;     
        ListNode*temp=head;
        while(temp!=NULL)
        {
            len++;        
            temp=temp->next;
        }
        int maxi=INT_MIN;    
        int i=0;
        while(head!=NULL)
        {
            if(i<(len/2))
            {
                s.push(head->val);
            }
            else if(i>=(len/2))
            {
                maxi=max(maxi, (head->val + s.top()));
                s.pop();
            }
            i++;
            head=head->next;           
        }
        return maxi;
    }
};