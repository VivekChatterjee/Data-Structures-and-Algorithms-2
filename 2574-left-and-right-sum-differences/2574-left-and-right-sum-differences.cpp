#define vi vector<int>
class Solution {
public:
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        int n = nums.size();
        vi ans(n), right(n);
        int sum = 0;
        right[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] + nums[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = abs(right[i] - sum);
            sum += nums[i];
        }
        return ans;
    }
};