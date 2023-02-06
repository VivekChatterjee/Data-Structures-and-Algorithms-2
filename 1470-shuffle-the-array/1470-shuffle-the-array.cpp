class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int mid=n, i=0;
        bool start=1;
        vector<int>ans;
        while((int)ans.size()<2*n)
        {
            if(start) ans.push_back(nums[i++]);
            else ans.push_back(nums[mid++]);
            start=!start;
        }
        return ans;
    }
};