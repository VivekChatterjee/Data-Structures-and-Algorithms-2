class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0, j=n-1;
        for(int k: nums)
        {
            if(k%2==0) ans[i++]=k;
            else ans[j--]=k;
        }
        return ans;
    }
};