#define ll long long int
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(auto i: roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<pair<int, int>>v; // {connections, node number}
        for(int i=0; i<n; i++)
        {
            v.push_back({adj[i].size(), i});
        }
        sort(v.begin(), v.end());
        unordered_map<int, int>m;
        int num = 1;
        for(auto i: v)
        {
            m[i.second] = num++;
        }
        ll ans = 0;
        for(auto it: roads)
        {
            ans+=(ll)m[it[0]] + (ll)m[it[1]];
        }
        return ans;
    }
};