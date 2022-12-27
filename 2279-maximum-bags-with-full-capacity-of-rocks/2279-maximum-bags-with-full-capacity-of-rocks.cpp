// #define ll long long int
// class Solution {
// public:
//     int bags(int i, vector<int>& cap, vector<int>& rocks, int add)
//     {
//         int n = cap.size();
//         if(i >= n) return 0;
//         // if(dp[i][add] != -1) return dp[i][add];
//         int dont = 0, take = 0;
//         // dont take
//         if(cap[i] == rocks[i]) dont = 1 + bags(i+1, cap, rocks, add);
//         else dont = 0 + bags(i+1, cap, rocks, add);
        
//         // take
//         // if(cap[i] == rocks[i]) take = 1 + bags(i+1, cap, rocks, add);
//         if(cap[i] > rocks[i] && (cap[i] - rocks[i]) <= add)
//         {
//             take = 1 + bags(i+1, cap, rocks, add - cap[i] - rocks[i]);
//         }
//         if(max(take, dont) == 2) cout<<i<<" yahan\n";
//         return max(take, dont);
//     }
//     int maximumBags(vector<int>& cap, vector<int>& rocks, int add) {
//         int n = cap.size();
//         // vector<vector<int>>dp(n+1, vector<int> (add+1, -1));
//         return bags(0, cap, rocks, add);
//     }
// };

class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int add) {
        int n = cap.size();
        vector<int>v;
        for(int i=0; i<n; i++)
        {
            if(cap[i] <= rocks[i]) v.push_back(0);
            else v.push_back(cap[i] - rocks[i]);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(v[i] <= add)
            {
                ans++;
                add-=v[i];
            }
            else break;
        }
        return ans;
    }
};