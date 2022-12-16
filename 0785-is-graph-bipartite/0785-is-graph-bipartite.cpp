class Solution {
public:
    bool isBip(bool one, int num, vector<vector<int>>& graph,  vector<int>&vis)
    {
        if(one) vis[num] = 1;
        else vis[num] = -1;
        // int n = graph.size();
        // cout<<num<<":"<<endl;
        // for(int i = 0; i<n;i++)
        //     cout<<vis[i]<<" ";
        // cout<<endl; 
        for(auto i: graph[num])
        {
            if(!vis[i]) if(!isBip(!one, i, graph, vis)) return 0;
            if(vis[i] && vis[i] == vis[num]) return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0);   
        for(int i=0; i<n; i++)
        {
            bool one = 1;
            if(!vis[i]) if(!isBip(one, i, graph, vis)) return 0;
        }   
        return 1;
    }
};

// aise nahi banega
// class Solution {
// public:
//     void dfs(int par, int num, int &len, bool &bip, vector<vector<int>>& graph
//             , vector<int>&vis)
//     {
//         vis[num] = 1;
//         for(auto i: graph[num])
//         {
//             if(!vis[i])
//             {
//                 if(bip) len++;
//                 // cout<<num<<" se "<<i<<" gaya\n";
//                 dfs(num, i, len, bip, graph, vis);
//             }
//             else if(vis[i] && i != par)
//             {
//                 // cout<<i<<" len= "<<len+1<<endl;
//                 if(bip && (len+1) % 2 != 0) bip = 0;
//             }
//         }
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int>vis(n);
//         for(int i=0; i<n; i++)
//         {
//             if(!vis[i])
//             {
//                 int len = 0;
//                 bool bip = 1;
//                 dfs(-1, i, len, bip, graph, vis);
//                 if(!bip) return 0;
//             }
//         }
//         return 1;
//     }
// };