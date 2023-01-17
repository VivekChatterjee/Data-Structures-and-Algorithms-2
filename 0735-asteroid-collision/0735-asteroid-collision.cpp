class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aster) {
        int n=aster.size();
        stack<int>st;
        for(int i=n-1; i>=0; i--)
        {
            bool c=0;
            if(!st.empty())
            {
                while(!st.empty() && aster[i] > 0 && st.top() < 0)
                {
                    if(abs(aster[i]) == abs(st.top()))
                    {
                        st.pop();
                        c=1;
                        break;
                        
                    }
                    else if(abs(aster[i]) > abs(st.top()))
                    {
                        st.pop();
                    }
                    else
                    {
                        c=1;
                        break;
                    }
                }
            }
            if(c) continue;
            st.push(aster[i]);
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};