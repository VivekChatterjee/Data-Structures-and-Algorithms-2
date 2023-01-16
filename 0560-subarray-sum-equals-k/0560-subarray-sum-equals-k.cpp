class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, ans=0;
        unordered_map<int, int>m;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            if(sum==k) ans++;
            if(m.count(sum-k)) ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};