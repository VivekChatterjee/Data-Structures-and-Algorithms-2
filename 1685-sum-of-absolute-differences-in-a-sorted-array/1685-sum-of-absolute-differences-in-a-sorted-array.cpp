class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n), right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1; i<n; i++) left[i]=left[i-1]+nums[i];
        for(int i=n-2; i>=0; i--) right[i]=right[i+1]+nums[i];
        vector<int>ans(n);
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                ans[i]=abs(right[i+1]-((n-1) * nums[i]));
            }
            else if(i==n-1)
            {
                ans[i]=abs(left[i-1]-((n-1) * nums[i]));
            }
            else
            {
                int l=0, r=0;
                l=abs(left[i-1]-(i * nums[i]));
                r=abs(right[i+1]-((n-i-1) * nums[i]));
                ans[i]=l+r;
            }
        }
        return ans;
    }
};