/*
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* copy=new Node(head->val);
        unordered_map<Node*, Node*>m;
        Node* start=copy, *headd= head;
        while(headd)
        {
            if(!headd->next)
            {
                start->next=NULL;
            }
            else
            {
                start->next=new Node(headd->next->val);
            }
            m[headd] = start;
            headd=headd->next;
            start=start->next;
        }
        start=copy;
        while(head)
        {
            start->next=m[head->next];
            start->random=m[head->random];
            head=head->next;
            start=start->next;
        }
        return copy;
    }
};