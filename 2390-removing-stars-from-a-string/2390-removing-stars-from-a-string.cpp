class Solution {
public:
    string removeStars(string &s) {
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='*') st.pop();
            if(s[i]!='*') st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            char c=st.top();
            st.pop();
            ans+=c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};