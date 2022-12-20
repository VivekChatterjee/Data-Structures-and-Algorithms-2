#define pipii pair<int, pair<int, int>>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1 && !grid[0][0]) return 1;
        // {distance, {rowNode, colNode}}
        priority_queue<pipii, vector<pipii>, greater<pipii>>p; 
        if(grid[0][0] == 0) p.push({1, {0, 0}});
        vector<vector<int>>dis(n, vector<int>(n, 1e7));
        while(!p.empty())
        {
            auto curElement = p.top();
            p.pop();
            int curDis = curElement.first;
            int curRow = curElement.second.first;
            int curCol = curElement.second.second;
            grid[curRow][curCol] = 1;
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    int ii = curRow + i;
                    int jj = curCol + j;
                    if(ii>=0 && ii<n && jj>=0 && jj<n && grid[ii][jj] == 0)
                    {
                        if(curDis + 1 < dis[ii][jj])
                        {
                            dis[ii][jj] = curDis + 1;
                            p.push({curDis + 1, {ii, jj}});
                        }
                    }
                }
            }
        }
        return (dis[n-1][n-1] == 1e7)? -1 : dis[n-1][n-1];
    }
};