#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        ll ct=0, ans=0;
        for(int i=0; i<=n; i++)
        {
            if(i==n)
            {
                ans+=((ct*(ct+1))/2);
            }
            else
            {
                if(nums[i]==0)
                {
                    ct++;
                }
                else
                {
                    ans+=((ct*(ct+1))/2);
                    ct=0;
                }
            }
        }
        return ans;
    }
};