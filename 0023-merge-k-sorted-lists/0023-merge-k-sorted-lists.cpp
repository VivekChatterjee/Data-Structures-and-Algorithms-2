class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& v) {
        int n=v.size();
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>p; 
        for(int i=0; i<n; i++)
        {
            if(v[i]) p.push({ v[i]->val, v[i]});
        }
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(!p.empty())
        {
            ListNode* top=p.top().second;
            p.pop();
            if(top->next)
            {
                p.push({top->next->val, top->next});
            }
            tail->next=top;
            tail=tail->next;
        }
        tail->next=NULL;
        return head->next;
    }
};