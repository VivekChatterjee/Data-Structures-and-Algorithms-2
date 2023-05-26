class Solution {
    int helper(vector<int>& piles, int ind, int turn, int M, vector<vector<vector<int>>>& dp) {
        if(ind == piles.size())
            return 0;
        if(dp[ind][M][turn] != -1) return dp[ind][M][turn];
        int n = min(2*M+ind, (int)piles.size());
        // cout<<ind<<" "<<turn<<" "<<M<<endl;
        int ans = (turn == 0)?INT_MAX:INT_MIN;;
        if(turn == 0){ //0-> Bob's turn
            for(int i = ind; i<n; i++) {
                ans = min(ans, helper(piles, i+1, 1, max(M, (i-ind+1)), dp));
            }
        }
        else {
         int pilesum = 0;
            for(int i = ind; i<n; i++) {
                pilesum += piles[i];
                ans = max(ans, pilesum+helper(piles, i+1, 0, max(M, (i-ind+1)), dp));
            }   
        }
        return dp[ind][M][turn] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 1) return piles[0];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return helper(piles, 0, 1, 1, dp);
        
    }
};