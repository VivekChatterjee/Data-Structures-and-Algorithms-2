class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& d) {
        int ans=INT_MAX, cur=INT_MIN;
        for(int i=0; i<d.size(); i++)
        {
            int ct=0;
            for(int it: nums)
            {
                if(it%d[i]==0) ct++;
            }
            if(ct>cur)
            {
                ans=d[i];
                cur=ct;
            }
            else if(ct==cur)
                ans=min(ans, d[i]);
        }
        return ans;
    }
};