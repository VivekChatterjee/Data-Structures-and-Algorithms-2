class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>uni;
    void seq(int i, int prev, vector<int>& nums, vector<int>res)
    {
        int n=nums.size();
        if(i==n)
        {
            if(res.size() >= 2) uni.insert(res);
            return;
        }
        // don't take
        seq(i+1, prev, nums, res);
        // take
        if(nums[i] >= prev)
        {
            res.push_back(nums[i]);
            seq(i+1, nums[i], nums, res);
        }        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        seq(0, -101, nums, res);
        for(auto i: uni) ans.push_back(i);
        return ans;
    }
};