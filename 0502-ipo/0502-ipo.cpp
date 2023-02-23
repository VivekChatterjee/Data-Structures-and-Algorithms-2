class Solution {
public:
    static bool cmp(pair<int, int>&a, pair<int, int>&b)
    {
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& cap) 
    {
        int n=cap.size();
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++)
        {
            v.push_back({cap[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int in=0, ans=w, cur=0;
        priority_queue<pair<int, int>>p; // {profit, cap}
        while((in<n && k)|| k)
        {
            while(in<n && v[in].first<=w)
            {
                p.push({v[in].second, v[in].first});
                in++;
            }
            if(p.empty()) break;
            w+=p.top().first;
            ans+=p.top().first;
            p.pop();
            k--;
        }
        return ans;
    }
};