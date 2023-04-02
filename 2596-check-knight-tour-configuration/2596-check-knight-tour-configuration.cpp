class Solution {
public:
    vector<int>row={-2,-2,+2,+2,-1,-1,+1,+1};
    vector<int>col={-1,+1,-1,+1,-2,+2,-2,+2};
    bool check(int cur, int i, int j, vector<vector<int>>& grid)
    {
        int n=grid.size();
        if(cur==(n*n-1)) return 1;
        bool possible=0;
        for(int k=0; k<8; k++)
        {
            int r=i+row[k];
            int c=j+col[k];
            if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==(cur+1)) 
                possible|=check(cur+1, r, c, grid);
            if(possible) return 1;
        }
        return possible;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0) return 0;
        return check(0, 0, 0, grid);
    }
};