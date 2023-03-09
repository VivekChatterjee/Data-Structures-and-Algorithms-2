//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*> ans;
        unordered_map<char, int>m, mp;
        for(char c: s) m[c]++;
        mp=m;
        int ct=m.size(), i=0, j=0, n=s.size(),prevj=-1;
        Node* start=head, *end;
        while(head)
        {
            end=head;
            m[head->data]--;
            if(m[head->data]==0) ct--;
            if(j-i+1==n)
            {
                if(ct==0 || (ct==0 && i>prevj))
                {
                    Node* nxt=end->next;
                    end->next=NULL;
                    if(i>prevj)
                    ans.push_back(start);
                    start=nxt;
                    head=nxt;
                    ct=mp.size();
                    m=mp;
                    prevj=j;
                    j++;
                    i=j;
                    continue;
                }
                m[start->data]++;
                if(m[start->data]==1) ct++;
                start=start->next;
                i++;
            }
            head=head->next;
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends