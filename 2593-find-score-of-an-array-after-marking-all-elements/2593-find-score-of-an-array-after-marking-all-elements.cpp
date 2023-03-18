#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    long long findScore(vector<int> &nums)
    {
        ll n = nums.size();
        ll ans = 0;
        vector<ll> vis(n);
        priority_queue<pll, vector<pll>, greater<pll>> p;
        for (int i = 0; i < n; i++)
        {
            p.push({nums[i], i});
        }
        while (!p.empty())
        {
            ll top = p.top().first;
            ll ind = p.top().second;
            if (!vis[ind])
            {
                ans += top;
                if (ind - 1 >= 0)
                    vis[ind - 1] = 1;
                if (ind + 1 < n)
                    vis[ind + 1] = 1;
            }
            p.pop();
        }
        return ans;
    }
};