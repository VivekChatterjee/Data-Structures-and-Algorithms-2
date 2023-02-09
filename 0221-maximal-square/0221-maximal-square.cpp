class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n));
        bool pos=0;
        for(int i=0; i<m; i++)
        {
            dp[i][0]=(matrix[i][0]=='1');
            if(matrix[i][0]=='1') pos=1;            
        }
        for(int j=0; j<n; j++)
        {
            dp[0][j]=(matrix[0][j]=='1');
            if(matrix[0][j]=='1') pos=1;   
        }
        int ans=0;
        if(pos) ans=1;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                    ans=max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};