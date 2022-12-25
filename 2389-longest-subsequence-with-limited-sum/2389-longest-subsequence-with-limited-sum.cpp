class Solution {
public:
    int longest(int i, vector<int>& nums, int sum)
    {
        int n = nums.size();
        if(i >= n) return 0;
        if(sum - nums[i] >= 0) return 1 + longest(i+1, nums, sum - nums[i]);
        else return 0;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<queries.size(); i++)
        {
            ans.push_back(longest(0, nums, queries[i]));
        }
        return ans;
    }
};