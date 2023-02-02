class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1,suf=1, ans=nums[0];
        for(int i=0; i<n; i++)
        {
            pre = ((pre)? pre : 1) * nums[i];
            suf = ((suf)? suf : 1) * nums[n-i-1];
            ans=max(ans, max(pre, suf));
        }
        return ans;
    }
};