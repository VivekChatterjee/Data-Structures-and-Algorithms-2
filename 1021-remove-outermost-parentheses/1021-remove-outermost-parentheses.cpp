class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size(), op=0, cl=0;
        string ans="";
        stack<char>st;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(') op++;
            else cl++;
            st.push(s[i]);
            if(op==cl)
            {
                st.pop();
                op=0;
                cl=0;
            }
        }
        op=0,cl=0;
        while(!st.empty())
        {
            if(st.top()=='(') op++;
            else cl++;
            if(op<=cl)
                ans.insert(ans.begin(), st.top());
            else
                op--;
            st.pop();
        }
        return ans;
    }
};