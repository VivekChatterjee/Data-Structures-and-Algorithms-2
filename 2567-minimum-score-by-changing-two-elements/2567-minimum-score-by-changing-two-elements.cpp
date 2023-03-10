class Solution {
public:
    int minimizeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int end = nums[n - 3], st = nums[2];
        // mi change 1st 2
        int mi = st, mx = nums[n - 1], mi2 = nums[0], mx2 = end;
        int ans = min({mx - mi, mx2 - mi2, abs(nums[n - 2] - nums[1])});
        return ans;
    }
};