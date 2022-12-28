class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& land, int &r, int &c, bool &found)
    {
        int m = land.size();
        int n = land[0].size();
        if(i<0 || i>=m || j<0 || j>=n || land[i][j] == 0 || land[i][j] == -1) return;
        land[i][j] = -1;
        dfs(i, j+1, land, r, c, found);
        dfs(i+1, j, land, r, c, found);
        if(!found) r=i, c=j, found = 1;
        dfs(i, j-1, land, r, c, found);
        dfs(i-1, j, land, r, c, found);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>>ans;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(land[i][j] == 1)
                {
                    vector<int>hec;
                    hec.push_back(i);
                    hec.push_back(j);
                    int r = i, c = j;
                    bool found = false;
                    dfs(i, j, land, r, c, found);
                    hec.push_back(r);
                    hec.push_back(c);
                    ans.push_back(hec);
                }
            }
        }
        return ans;
    }
};