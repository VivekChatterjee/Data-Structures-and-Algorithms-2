class Solution {
public:
    int K=1e9+7;
    int good(int i, string &binary, vector<int>&dp, vector<vector<int>>&pre)
    {
        int n=binary.size();
        // if there are no more characters to add
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        ans+=(good(pre[i][1], binary, dp, pre)+good(pre[i][0], binary, dp, pre))%K;
        return dp[i]=ans;
    }
    int numberOfUniqueGoodSubsequences(string binary) {
        int n=binary.size(), last0=n+1, last1=n+1;
        bool present=0;
        vector<vector<int>>pre(n, vector<int>(2));
        pre[n-1][0]=last0, pre[n-1][1]=last1;
        if(binary[n-1]=='0')
        {
            last0=n-1;
            present=1;
        }
        else last1=n-1;
        for(int i=n-2; i>=0; i--)
        {
            if(binary[i]=='0') present=1;
            pre[i][0]=last0;
            pre[i][1]=last1;
            if(binary[i]=='0') last0=i;
            else last1=i;
        }
        vector<int>dp(n, -1);
        int ans=good(last1, binary, dp, pre);
        if(present) ans++;
        return ans;
    }
};