#define ll long long
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        ll n=nums.size(), sum=0, ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            ans=max(ans, (sum+i)/(i+1));
        }
        return ans;
    }
};