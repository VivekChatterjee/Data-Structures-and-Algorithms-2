class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++) q.push({tickets[i], i});
        int ans=0;
        while(!q.empty())
        {
            auto f=q.front();
            f.first--;
            ans++;
            if(f.second == k && f.first == 0) break;
            if(f.second == k || f.first >= 1) q.push({f.first, f.second});
            q.pop();
        }
        return ans;
    }
};