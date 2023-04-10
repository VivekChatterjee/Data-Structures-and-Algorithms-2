class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++)
        {
            bool took=0;
            if(!st.empty() && ((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}')))
            {
                took=1;
                st.pop();
            }
            if(!took) st.push(s[i]);            
        }
        return st.empty();
    }
};