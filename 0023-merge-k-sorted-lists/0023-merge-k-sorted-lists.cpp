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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        int n=v.size();
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(true)
        {
            int mini=INT_MAX, cur;
            for(int i=0; i<n; i++)
            {
                if(v[i])
                {
                    if(v[i]->val < mini)
                    {
                        mini=v[i]->val;
                        cur=i;
                    }
                }
            }
            if(mini==INT_MAX) break;
            else
            {
                tail->next=v[cur];
                v[cur]=v[cur]->next;
                tail=tail->next;
            }
        }
        return head->next;
    }
};