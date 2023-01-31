// #define pii pair<int, int>
// class Solution {
// public:
//     int score(int i, int mini, vector<pii>v, vector<vector<int>>&dp)
//     {
//         int n=v.size();
//         if(i==n) return 0;
//         else if(i == n-1) return v[i].first;
//         if(dp[i][mini] != -1) return dp[i][mini];
//         int take=0, dont=0;
//         dont = 0 + score(i+1, mini, v, dp);
//         if(v[i].second >= mini)
//         take = v[i].first + score(i+1, min(v[i].second, mini), v, dp);
//         return dp[i][mini] = max(take, dont);
//     }
//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//         int n=ages.size();
//         vector<pii>v;
//         for(int i=0; i<n; i++)
//         {
//             v.push_back({scores[i], ages[i]});
//         }
//         sort(v.begin(), v.end(), greater<pii>());
//         vector<vector<int>>dp(n, vector<int>(1001, -1));
//         return score(0, ages[0], v, dp);
//     }
// };

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<tuple<int,int>> items;
        for (int i = 0; i < size(scores); ++i) items.push_back({scores[i], ages[i]});
        sort(begin(items), end(items));

        map<int,int> res; res[0] = 0;
        for(auto [sc, ag] : items) {
            auto it0 = res.upper_bound(ag);
            int sc2 = sc + (--it0)->second;
            auto it = res.insert(it0, {ag, sc2});
            if (it->second < sc2) it->second = sc2;
            ++it;
            while (it != res.end() && it->second <= sc2) {
                auto it2 = it++;
                res.erase(it2);
            }
        }
        return res.rbegin()->second;
    }
};