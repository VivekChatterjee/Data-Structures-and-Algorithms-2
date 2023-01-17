class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size(), k=n-1;
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--)
        {
            int maxi=heights[i], ct=0;
            while(!st.empty())
            {
                ct++;
                if(st.top() > heights[i]) break;
                else
                st.pop();
            }
            st.push(heights[i]);
            ans[k--]=(st.empty())? 0 : ct;
        }
        return ans;
    }
};