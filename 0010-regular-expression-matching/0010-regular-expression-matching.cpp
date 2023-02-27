class Solution {
public:
    bool match(int i, int j, string& s, string& p, vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return 1;
        if(j<0) return 0;
        if(i<0)
        {
            return (p[j]=='*' && match(i, j-2, s, p, dp));
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=0;
        if(p[j]=='.' || s[i]==p[j])
            return dp[i][j]=match(i-1, j-1, s, p, dp);
        else if(p[j]=='*')
        {
            bool one=0, two=0;
            // take no char
            one=match(i, j-2, s, p, dp);
            // take single char + multi char
            two=((p[j-1]=='.' || s[i]==p[j-1]) && match(i-1, j, s, p, dp));   
            ans=one||two;
        }
        return dp[i][j]=ans;
    }        
    bool isMatch(string s, string p) {
        int n=s.size(), np=p.size();
        vector<vector<int>>dp(n+1, vector<int>(np+1, -1));
        return match(n-1, np-1, s, p, dp);
    }
};