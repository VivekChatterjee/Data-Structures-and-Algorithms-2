#define ll long long
#define pb push_back
#define vvi vector<vector<int>>
class Solution {
public:
    int countWays(vector<vector<int>> &v)
    {
        ll K = 1e9 + 7;
        int n = v.size();
        sort(v.begin(), v.end());
        vvi vec;
        vec.pb(v[0]);
        for (int i = 1; i < n; i++)
        {
            if (v[i][0] <= vec.back()[1])
            {
                vec.back()[1] = max(vec.back()[1], v[i][1]);
                vec.back()[0] = min(vec.back()[0], v[i][0]);
            }
            else
                vec.pb(v[i]);
        }
        ll sz=vec.size();
        ll ans=1;
        while(sz--)
        {
            ans=ans*2%K;
        }
        return ans;
    }
};