class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& cap) 
    {
        int n=cap.size();
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++)
        {
            v.push_back({cap[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int in=0;
        priority_queue<int>p; // {profit}
        while((in<n && k) || k)
        {
            while(in<n && v[in].first<=w)
            {
                p.push(v[in].second);
                in++;
            }
            if(p.empty()) break;
            w+=p.top();
            p.pop();
            k--;
        }
        return w;
    }
};