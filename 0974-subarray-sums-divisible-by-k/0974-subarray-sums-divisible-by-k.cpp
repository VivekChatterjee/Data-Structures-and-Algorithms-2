class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, ans=0;
        unordered_map<int, int>m;
        m[0]++;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};