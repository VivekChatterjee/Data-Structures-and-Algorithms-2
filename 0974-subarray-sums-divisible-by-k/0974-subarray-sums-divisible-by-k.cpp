class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(), ans=0, sum=0;
        unordered_map<int, int>m;
        m[0]++;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            if(m.count(rem)) ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};