//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& is, vector<int>&vis, int i){
        vis[i]=1;
        for(int j=0; j<is[0].size(); j++){
            if(is[i][j] && !vis[j])
            {
                dfs(is, vis, j);
            }
        }
    }
    int numProvinces(vector<vector<int>> is, int V) {
        int num=0;
        vector<int>vis(is.size());
        for(int i=0; i<is.size(); i++){
            if(is[i][i] && !vis[i])
            {
                num++;
                dfs(is, vis, i);
            }
        }
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends