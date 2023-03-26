class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        vector<bool>prime(1001, 1);
        for(int i=2; i*i<=1000; i++)
        {
            if(prime[i])
            {
                for(int j=i*i; j<=1000; j+=i)
                {
                    prime[j]=0;
                }
            }
        }
        prime[1]=0;
        prime[0]=0;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1]) continue;
            int diff=nums[i]-nums[i+1];
            int last=-1;
            for(int cur=diff+1; cur<nums[i]; cur++)
            {
                if(prime[cur])
                {
                    last=cur;
                    break;
                }
            }
            if(last == -1) return 0;
            nums[i] -= last;
        }
        return 1;
    }
};