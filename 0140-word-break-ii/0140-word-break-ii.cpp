class Solution {
public:
    vector<string> ans;
    bool breakWord(int i, string &s, unordered_map<string, int>&m,                       vector<int>&dp, string &a)
    {
        int n=s.size();
        if(i==n)
        {
            return 1;
        }
        // if(dp[i] != -1) return dp[i];
        for(int k=i; k<n; k++)
        {
            string cur=s.substr(i, k-i+1);
            if(m.count(cur))
            {
                string b=a;
                a=a+cur+" ";
                if(breakWord(k+1, s, m, dp, a))
                {
                    a.pop_back();
                    ans.push_back(a);
                }
                a=b;
            }
        }
        return 0;
    }
    vector<string> wordBreak(string s, vector<string>& w) {
        int n=s.size();
        unordered_map<string, int>m;
        for(auto &i: w) m[i]++;
        vector<int>dp(n+1, -1);
        string a="";
        breakWord(0, s, m, dp, a);
        return ans;
    }
};