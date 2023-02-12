#define ll long long
class Solution {
public:
    ll ans=0;
    ll fuel(int node, int par, vector<int>adj[], int seats)
    {
        ll city=1;
        for(auto cur: adj[node])
        {
            if(cur != par) city += fuel(cur, node, adj, seats);
        }
        if(node>0) ans+=(city+seats-1)/seats;
        return city;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int>adj[n+1];
        for(auto it: roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        fuel(0, -1, adj, seats);
        return ans;
    }
};