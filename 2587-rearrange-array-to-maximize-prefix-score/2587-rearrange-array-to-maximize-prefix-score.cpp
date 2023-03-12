#define ll long long
#define vll vector<ll>
class Solution {
public:
    int maxScore(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        vll pre(n);
        pre[0] = (ll)(nums[0]);
        int ans = 1;
        if (pre[0] <= 0)
            return 0;
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + (ll)nums[i];
            if (pre[i] <= 0)
                return ans;
            else
                ans++;
        }
        return ans;
    }
};