class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        // stop at nearest smaller to left and nsr
        stack<int>s, st;
        vector<int>nsl(n), nsr(n);
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() and heights[s.top()] >= heights[i]) s.pop();
            nsr[i]=(s.empty())? n : s.top();
            s.push(i);
        }
        for(int i=0; i<n; i++)
        {
            while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            nsl[i]=(st.empty())? -1 : st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            ans=max(ans, (nsr[i] - nsl[i] - 1)*heights[i]);
        }
        return ans;
    }
};