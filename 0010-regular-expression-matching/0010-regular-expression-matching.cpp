class Solution {
public:
    bool match(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        int n=s.size(), np=p.size();
        if(i==-1 and j==-1) return 1; //both ends
        else if(i==-1) return (p[j]=='*' and match(i, j-2, s, p, dp));
        else if(j==-1) return 0; //only pattern ends
        if(dp[i][j]!=-1) return dp[i][j];
        //single character matches
        if(p[j]=='.' or p[j]==s[i]) return dp[i][j]=match(i-1,j-1, s, p, dp);
        if(p[j]=='*')
        {
            bool one=  match(i, j-2, s, p, dp);
            bool two=match(i, j-1, s, p, dp);
            bool three= ((p[j-1]=='.' or s[i]==p[j-1]) and match(i-1, j, s, p, dp));
            return dp[i][j]=(one|two|three);
        }
        return 0;
    }
    bool isMatch(string s, string p) 
    {
        int n=s.size(), np=p.size();
        vector<vector<int>>dp(n+1, vector<int>(np+1, -1));
        return match(n-1, np-1, s, p, dp);
    }
};