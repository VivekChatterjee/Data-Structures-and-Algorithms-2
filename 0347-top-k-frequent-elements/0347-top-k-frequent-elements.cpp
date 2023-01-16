class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int>m;
        for(int i: nums) m[i]++;
        vector<pair<int, int>>v;
        for(auto i: m) v.push_back({i.second, i.first});
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        vector<int>ans;
        for(auto i: v)
        {
            ans.push_back(i.second);
            if(ans.size() == k) break;
        }
        return ans;
    }
};