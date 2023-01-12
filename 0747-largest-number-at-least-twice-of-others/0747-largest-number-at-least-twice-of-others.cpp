class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]=i;
        sort(nums.begin(), nums.end());
        int big=nums[nums.size()-1];
        for(int i=0; i<nums.size()-1; i++)
        {
            if(big<(2*nums[i])) return -1;
        }
        return m[big];
    }
};