class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int odd=0, even=0;
        for(int i=0; i<n; i++)
        {
            if(i%2) odd+=piles[i];
            else even+=piles[i];
        }
        return (odd>even || even>odd);
    }
};