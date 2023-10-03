class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int>m;
        int ans=0;
        for(int i=nums.size()-1; i>=0; i--)
        {
            ans+=m[nums[i]];
            m[nums[i]]++;
        }
        return ans;
    }
};