class Solution
{
public:
    int minExtraChar(string s, vector<string> &d)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            int k = dp[i] + dp[i];
            bool flag = 0;
            for (auto w : d)
            {
                if (i >= w.size() && s.substr(i - w.size(), w.size()) == w)
                {
                    int j = i - w.size();
                    dp[i] = min(dp[i], dp[j]);
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag)
                break;
        }
        return dp[n];
    }
};