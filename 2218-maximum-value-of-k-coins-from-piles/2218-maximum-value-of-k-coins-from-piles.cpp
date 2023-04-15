class Solution {
public:
    int coins(int i, int j, int k, vector<vector<int>>&piles, vector<vector<vector<int>>> &dp)
    {
        int n=piles.size();
        if(i==n) return 0;
        int nn=piles[i].size();
        if(k==0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int take=0, dont=0;
        dont=0+coins(i+1, 0, k, piles, dp);
        if(j<nn)
        take+=piles[i][j]+coins(i, j+1, k-1, piles, dp);
        return dp[i][j][k]=max(dont, take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size(), nn=INT_MIN;
        for(int i=0; i<n; i++) nn=max(nn, (int)piles[i].size());
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(nn+1, vector<int>(k+1, -1)));
        return coins(0, 0, k, piles, dp);
    }
};