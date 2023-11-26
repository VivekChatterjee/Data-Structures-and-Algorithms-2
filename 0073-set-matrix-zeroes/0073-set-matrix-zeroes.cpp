class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int zeroCol=1;
        for(int i=0; i<m.size(); i++)
        {
            for(int j=0; j<m[i].size(); j++)
            {
                if(!m[i][j] && !j)
                {
                    zeroCol=0;
                    m[i][0]=0;
                }
                else if(!m[i][j])
                {
                    m[i][0]=0;
                    m[0][j]=0;
                }
            }
        }
        for(int i=m.size()-1; i>=0; i--)
        {
            for(int j=m[i].size()-1; j>=1; j--)
            {
                m[i][j] = (m[i][0] == 0 || m[0][j] == 0) ? 0 : m[i][j]; 
            }
        }
        if (!zeroCol)
        for(int i=0; i<m.size(); i++)
        {
            m[i][0]=0;
        }
    }
};