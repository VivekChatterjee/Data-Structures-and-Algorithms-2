class Solution {
public:
    const int K=1e9+7;
    int threeSumMulti(vector<int>& nums, int target) {
        int n=nums.size(), ans=0;
        unordered_map<int, int>m;
        for(int i=0; i<n; i++)
        {
            ans = (ans + m[target-nums[i]]) % K;
            for(int j=0; j<i; j++)
            {
                int twoSum=nums[i]+nums[j];
                m[twoSum]++;
            }
        }
        return ans;
    }
};