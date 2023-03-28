class Solution {
public:
    int cost(int i, vector<int>& days, vector<int>& costs, int canGoTill,  vector<vector<int>>&dp)
    {
        int n=days.size();
        if(i==n) return 0;
        if(dp[i][canGoTill]!=-1) return dp[i][canGoTill];
        if(days[i]<=canGoTill) return dp[i][canGoTill]=cost(i+1, days, costs, canGoTill, dp);
        int one=costs[0]+cost(i+1, days, costs, days[i], dp);
        int seven=costs[1]+cost(i+1, days, costs, days[i]+7-1, dp);
        int month=costs[2]+cost(i+1, days, costs, days[i]+30-1, dp);
        return dp[i][canGoTill]=min({one, seven, month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>>dp(n, vector<int>(396, -1));
        return cost(0, days, costs, 0, dp);
    }
};