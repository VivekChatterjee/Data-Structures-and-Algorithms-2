class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+2, vector<int>(n+2));
        for(int gap=0; gap<n; gap++)
        {
            for(int i=1,j=1+gap; i<=n && j<=n; i++, j++)
            {
                if(gap==0) dp[i][j]=1;
                else if(gap==1)
                {
                    if(s[i-1]==s[j-1]) dp[i][j]=2;
                }
                else if(gap>1)
                {
                    if(s[i-1]==s[j-1] && dp[i+1][j-1])
                    dp[i][j]=2+dp[i+1][j-1];
                }
            }
        }
        int i=-1, maxi=INT_MIN;
        for(int ii=1; ii<=n; ii++)
        {
            for(int jj=1; jj<=n; jj++)
            {
                if(dp[ii][jj])
                {
                    if(jj-ii+1>maxi)
                    {
                        maxi=jj-ii+1;
                        i=ii-1;
                    }
                }
            }
        }
        if(i==-1) return "";
        else return s.substr(i, maxi);
    }
};