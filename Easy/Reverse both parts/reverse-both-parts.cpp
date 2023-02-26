//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    Node* my(Node* root){
        Node* head,*middle,*tail;
        head=root;
        middle=NULL;
        while(head)
        {
            tail=middle;
            middle=head;
            head=head->next;
            middle->next=tail;
        }
        return middle;
    }
    Node *reverse(Node *head, int k)
    {
        int c=0;
        Node* prev=NULL;
        Node* curr=head;
        while(c<k)
        {
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
        }
        head->next=my(curr);
        return prev;
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends