class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size(), ans=0, diff=INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            int j=i+1, k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                int curD=abs(target-sum);
                if(curD < diff) 
                {
                    diff=curD;
                    ans=sum;
                }
                if(sum==target)
                {
                    j++;
                    k--;
                }
                else if(sum<target) j++;
                else k--;
            }
        }
        return ans;
    }
};