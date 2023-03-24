#define ll long long int
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans=0;
        ll i=0, j=0;
        unordered_map<int,int>m;
        int n=nums.size();
        ll maxSum=0;
        ll cur=0;
        while(i<=j && j<n)
        {
            if(m.count(nums[j]))
            {
                while(m.count(nums[j]) && i<j)
                {
                    m.erase(nums[i]);
                    cur-=nums[i];
                    i++;
                }
                cur+=nums[j];
                m[nums[j]]++;
            }
            else if(!m.count(nums[j]))
            {
                cur+=nums[j];
                m[nums[j]]++;
                if(j-i+1 == k)
                {
                    maxSum=max(maxSum, cur);
                    cur-=nums[i];
                    m.erase(nums[i]);
                    i++;
                }
            }
            j++;
        }
        return maxSum;
    }
};