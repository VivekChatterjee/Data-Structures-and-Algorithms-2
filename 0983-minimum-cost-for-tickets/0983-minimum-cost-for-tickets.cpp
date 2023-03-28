class Solution {
public:
    int cost(int i, vector<int>& days, vector<int>& costs, vector<int>&dp)
    {
        int n=days.size();
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int one=0, seven=0, month=0;
        one=costs[0]+cost(i+1, days, costs, dp);
        int toSeven=-1, toMonth=-1;
        for(int j=i+1; j<n; j++)
        {
            if(days[j]-days[i]>=7)
            {
                toSeven=j;
                break;
            }
        }
        if(toSeven==-1)
        {
            seven=costs[1]+cost(n, days, costs, dp);
        }
        else
        {
            seven=costs[1]+cost(toSeven, days, costs, dp);
        }
        for(int j=i+1; j<n; j++)
        {
            if(days[j]-days[i]>=30)
            {
                toMonth=j;
                break;
            }
        }
        if(toMonth==-1)
        {
            month=costs[2]+cost(n, days, costs, dp);
        }
        else
        {
            month=costs[2]+cost(toMonth, days, costs, dp);
        }
        return dp[i]=min({one, seven, month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n, -1);
        return cost(0, days, costs, dp);
    }
};