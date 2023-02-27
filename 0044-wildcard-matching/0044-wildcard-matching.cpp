class Solution {
public:
    bool match(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        int n=s.size(), np=p.size();
        if(i==n and j==np) 
            return 1; //both ends
        if(i==n and p[j]!='*') 
            return 0; //string ends but pattern doesnt have *
        if(j==np) 
            return dp[i][j]=0; //only pattern ends
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        //single character matches
        if((p[j]==s[i]) or p[j]=='?') 
            return dp[i][j]=match(i+1,j+1, s, p, dp);
        
        bool one=0, two=0, three=0, pos=0;
        if(p[j]=='*')
        {
            one=match(i, j+1, s, p, dp); //empty char match
            if(i!=n)
            two=match(i+1, j, s, p, dp); //single char + multipe char match
            if(i!=n)
            three=match(i+1, j+1, s, p, dp); //char and pattern both move ahead
            pos=one|two|three;
        }
        return dp[i][j]=pos;
    }
    bool isMatch(string s, string p) 
    {
        int n=s.size(), np=p.size();
        vector<vector<int>>dp(n+1, vector<int>(np+1, -1));
        return match(0, 0, s, p, dp);
    }
};