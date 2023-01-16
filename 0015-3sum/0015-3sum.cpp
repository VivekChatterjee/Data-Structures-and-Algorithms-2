class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i=0; i<n; i++)
        {
            int j=i+1, k=n-1;
            int target=-nums[i];
            while(j<k)
            {
                if(nums[j]+nums[k] == target)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k] < target) j++;
                else k--;
            }
        }
        for(auto i: s) ans.push_back(i);
        return ans;        
    }
};