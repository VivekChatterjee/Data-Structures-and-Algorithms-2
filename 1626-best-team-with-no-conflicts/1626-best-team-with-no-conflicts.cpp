#define pii pair<int, int>
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pii>v;
        for(int i=0; i<n; i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        vector<int>ans(n);
        int res=0;
        for(int i=0; i<n; i++)
        {
            ans[i]=v[i].second;
            for(int j=0; j<i; j++)
            {
                if(v[i].second >= v[j].second)
                ans[i]=max(ans[i], ans[j] + v[i].second);
            }
            res=max(res, ans[i]);
        }
        return res;
    }
};