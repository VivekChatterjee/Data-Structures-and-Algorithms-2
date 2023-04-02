class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]<0)
            {
                nums[i]=(abs(nums[i]/val)*val)+val+nums[i];
            }
        }
        map<int, int>m;
        for(int i: nums)
        {
            m[i%val]++;
        }
        int last=0;
        for(int i=0; i<n; i++)
        {
            if(m[i%val]==0)
            {
                return i;
            }
            else
            {
                m[i%val]--;
                last=i;
            }
        }
        return last+1;        
    }
};