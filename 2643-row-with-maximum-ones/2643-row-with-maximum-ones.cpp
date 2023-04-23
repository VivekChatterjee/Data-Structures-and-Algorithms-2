class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans(2);
        int maxi=INT_MIN;
        for(int i=0; i<mat.size(); i++)
        {
            int ct=0;
            for(int j=0; j<mat[i].size(); j++)
            {
                if(mat[i][j]==1) ct++;
            }
            if(ct>maxi)
            {
                ans[0]=i;
                ans[1]=ct;
                maxi=ct;
            }
        }
        return ans;
    }
};