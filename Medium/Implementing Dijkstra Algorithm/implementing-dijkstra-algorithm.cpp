//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int, int>
class Solution
{
	public:
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int>distance(v, 1e8);
        distance[s]=0;
        priority_queue<pii, vector<pii>, greater<pii>>p; // {distance, node}
        p.push({0, s});
        while(!p.empty())
        {
            int dis=p.top().first;
            int node=p.top().second;
            p.pop();
            for(auto &nbr: adj[node])
            {
                int curDis=nbr[1];
                int curNode=nbr[0];
                if(dis+curDis<distance[curNode])
                {
                    distance[curNode]=dis+curDis;
                    p.push({dis+curDis, curNode});
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends