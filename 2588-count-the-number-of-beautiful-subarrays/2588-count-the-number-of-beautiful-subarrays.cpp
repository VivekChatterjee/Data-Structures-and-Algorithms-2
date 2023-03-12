#define ll long long
#define vll vector<ll>
#define umapll unordered_map<ll, ll>
class Solution {
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vll xx(n);
        xx[0] = nums[0];
        for (ll i = 1; i < n; i++)
            xx[i] = xx[i - 1] ^ nums[i];
        umapll m;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll cur = 0 ^ xx[i];
            ans += (ll)m[cur];
            if (xx[i] == 0)
                ans++;
            m[xx[i]]++;
        }
        return ans;
    }
};