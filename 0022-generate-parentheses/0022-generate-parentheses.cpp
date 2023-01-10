class Solution {
public:
    vector<string>ans;
    void solve(int open, int total, string s)
    {
        if(total == 0)
        {
            if(open == 0) ans.push_back(s);
            return;
        }
        if(open==0)
        {
            s+='(';
            solve(open+1, total-1, s);
        }
        else
        {
            s+='(';
            solve(open+1, total-1, s);
            s.pop_back();
            s+=')';
            solve(open-1, total-1, s);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        string s="";
        solve(open, n*2, s);
        return ans;
    }
};