#define pipii pair<int, pair<int, int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 1 && n == 1) return 0;
        // {distance, {rowNode, colNode}}
        priority_queue<pipii, vector<pipii>, greater<pipii>>p;
        // priority_queue<pipii>p;
        p.push({0, {0, 0}});
        vector<vector<int>>dis(m, vector<int>(n, 1e7));
        vector<int>row={-1, 0, 1, 0}, col = {0, -1, 0, 1};
        while(!p.empty())
        {
            auto curElement = p.top();
            p.pop();
            int curDis = curElement.first;
            int curRow = curElement.second.first;
            int curCol = curElement.second.second;
            if(curRow == m-1 && curCol == n-1) return curDis;
            for(int i=0; i<4;i++)
            {
                int ii = curRow + row[i];
                int jj = curCol + col[i];
                if(ii>=0 && ii<m && jj>=0 && jj<n)
                {
                    int abv = max(curDis, abs(grid[ii][jj] - grid[curRow][curCol]));
                    if(abv < dis[ii][jj])
                    {
                        dis[ii][jj] = abv;
                        p.push({abv, {ii, jj}});
                    }
                }
            }
        }
        return -1;
    }
};