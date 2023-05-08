class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans=0, m=mat.size(), n=mat[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]!=-1 && (i==j || i+j==n-1))
                {
                    ans+=mat[i][j];
                    mat[i][j]=-1;
                }
            }
        }
        return ans;
    }
};