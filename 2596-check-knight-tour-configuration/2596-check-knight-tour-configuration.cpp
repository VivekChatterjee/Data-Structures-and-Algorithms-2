class Solution {
public:
    bool check(int cur, int i, int j, vector<vector<int>>& grid)
    {
        int n=grid.size();
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=cur) return 0;
        if(cur==(n*n-1))
        {
            return 1;
        }
        bool ul=check(cur+1, i-2, j-1, grid);
        bool ur=check(cur+1, i-2, j+1, grid);
        bool dl=check(cur+1, i+2, j-1, grid);
        bool dr=check(cur+1, i+2, j+1, grid);
        bool lu=check(cur+1, i-1, j-2, grid);
        bool ld=check(cur+1, i+1, j-2, grid);
        bool ru=check(cur+1, i-1, j+2, grid);
        bool rd=check(cur+1, i+1, j+2, grid);
        return (ul || ur || dl || dr || lu || ld || ru || rd);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0) return 0;
        return check(0, 0, 0, grid);
    }
};