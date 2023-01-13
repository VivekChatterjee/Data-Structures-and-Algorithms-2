class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>>m;
        int n=nums.size();
        for(int i=0; i<n;i++)
        {
            m[nums[i]].push_back(i);
        }
        for(auto i: m)
        {
            for(int j=1; j<i.second.size(); j++)
            {
                if(i.second[j] - i.second[j-1] <= k) return 1;
            }
        }
        return 0;
    }
};