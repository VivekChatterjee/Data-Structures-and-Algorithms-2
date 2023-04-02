class Solution {
public:
    static bool cmp(pair<int, int>&a, pair<int, int>&b)
    {
        return a.first-a.second > b.first-b.second;
    }
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        vector<pair<int, int>>v;
        int n=a.size();
        for(int i=0; i<n; i++)
        {
            v.push_back({a[i], b[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(i<k)
                ans+=v[i].first;
            else
                ans+=v[i].second;
        }
        return ans;
    }
};