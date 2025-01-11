//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void topoSort(vector<int>adj[], vector<int>&vis, stack<int>&s, int node){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) topoSort(adj, vis, s, it);
        }
        s.push(node);
    }
    string findOrder(vector<string> dict, int k) {
        string ans="";
        vector<int>adj[k];
        for(int i=0; i<dict.size()-1; i++){
            string w1=dict[i];
            string w2=dict[i+1];
            int j=0, k=0;
            while(j<w1.size() && k<w2.size()){
                if(w1[j]!=w2[k]){
                    adj[w1[j]-'a'].push_back(w2[k]-'a');
                    break;
                }
                j++;
                k++;
            }
        }
        stack<int>s;
        vector<int>vis(k);
        for(int i=0; i<k; i++){
            if(!vis[i])
            topoSort(adj, vis, s, i);
        }
        while(!s.empty()){
            ans+=(char)(s.top()+97);
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends