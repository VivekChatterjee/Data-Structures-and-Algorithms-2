class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>&vis)
    {
        int m = board.size();
        int n = board[0].size();
        vis[i][j] = 1;
        if(i-1>=0 && board[i-1][j]=='O' && !vis[i-1][j]) dfs(i-1,j,board,vis);
        if(j-1>=0 && board[i][j-1]=='O' && !vis[i][j-1]) dfs(i,j-1,board,vis);
        if(i+1<m && board[i+1][j]=='O' && !vis[i+1][j]) dfs(i+1,j,board,vis);
        if(j+1<n && board[i][j+1]=='O' && !vis[i][j+1]) dfs(i,j+1,board,vis);
    }
    void dfs2(int i, int j, vector<vector<char>>& board, vector<vector<int>>&vis)
    {
        int m = board.size();
        int n = board[0].size();
        vis[i][j] = 1;
        board[i][j] = 'X';
        if(i-1>=0 && board[i-1][j]=='O' && !vis[i-1][j]) dfs2(i-1,j,board,vis);
        if(j-1>=0 && board[i][j-1]=='O' && !vis[i][j-1]) dfs2(i,j-1,board,vis);
        if(i+1<m && board[i+1][j]=='O' && !vis[i+1][j]) dfs2(i+1,j,board,vis);
        if(j+1<n && board[i][j+1]=='O' && !vis[i][j+1]) dfs2(i,j+1,board,vis);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j< n;j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && !vis[i][j] && board[i][j] == 'O')
                    dfs(i, j, board, vis);
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j< n;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                    dfs2(i, j, board, vis);
            }
        }
    }
};