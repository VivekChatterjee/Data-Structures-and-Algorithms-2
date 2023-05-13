class Solution
{
public:
    int sumOfPower(vector<int>& nums) {
        long long mod = 1e9 + 7, pre = 0, res = 0;
        sort(nums.begin(), nums.end());
        for (long long x: nums) {
            res = (res + (x * x % mod) * x % mod + (x * x % mod) * pre % mod) % mod;
            pre = (pre * 2 + x) % mod;
        }
        return res;
    }
};