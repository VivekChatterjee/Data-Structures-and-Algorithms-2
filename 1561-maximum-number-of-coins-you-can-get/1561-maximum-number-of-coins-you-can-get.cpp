class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int n = piles.size(), i = 0, ind = 1, ans = 0;
        while(i < n/3)
        {
            ans += piles[ind];
            ind += 2;
            i++;
        }
        return ans;
    }
};