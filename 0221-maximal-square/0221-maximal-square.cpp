class Solution {
public:
    int maxAreaHistogram(int i, vector<vector<int>>& matrix)
    {
        int n=matrix[0].size();
        stack<int>s,st;
        vector<int>left(n), right(n);
        for(int j=n-1; j>=0; j--)
        {
            while(!s.empty() and matrix[i][s.top()] >= matrix[i][j]) s.pop();
            right[j]=(s.empty())? n : s.top();
            s.push(j);
        }
        for(int j=0; j<n; j++)
        {
            while(!st.empty() and matrix[i][st.top()] >= matrix[i][j]) st.pop();
            left[j]=(st.empty())? -1 : st.top();
            st.push(j);
        }
        int ans=INT_MIN;
        for(int j=0; j<n; j++)
        {
            int width = (right[j] - left[j] - 1);
            int height = matrix[i][j];
            int side = min(width, height);
            ans = max(ans, side*side);
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size(), c=matrix[0].size(), ans=INT_MIN;
        vector<vector<int>>vec(r, vector<int>(c));
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(i==0)
                {
                    vec[i][j] = matrix[i][j] - '0';
                }
                else if(matrix[i][j] != '0')
                {
                    if(matrix[i-1][j] != '0')
                        vec[i][j] = 1 + (vec[i-1][j]);
                    else
                        vec[i][j] = matrix[i][j] - '0';
                }
            }
        }
        for(int i=0; i<r; i++)
        {
            ans=max(ans, maxAreaHistogram(i, vec));
        }
        return ans;
    }
};