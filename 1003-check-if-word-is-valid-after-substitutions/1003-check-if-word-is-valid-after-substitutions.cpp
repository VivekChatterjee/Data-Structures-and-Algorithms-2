class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size(), i=0;
        while(i<n)
        {
            char ch=s[i];
            st.push(ch);
            if(ch=='c')
            {
                int i=0;
                i++;
                st.pop();
                if(!st.empty() && st.top()=='b')
                {
                    i++;
                    st.pop();
                    if(!st.empty() && st.top()=='a')
                    {
                        i++;
                        st.pop();
                    }
                }
                if(i==2)
                {
                    st.push('b');
                    st.push('c');
                }
                else if(i==1)
                {
                    st.push('c');
                }
            }
            i++;
        }
        return st.empty();
    }
};