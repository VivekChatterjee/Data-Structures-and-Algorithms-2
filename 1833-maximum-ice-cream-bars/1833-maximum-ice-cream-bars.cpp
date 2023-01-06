class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int i: costs)
        {
            if(i > coins || coins == 0) break;
            ans++;
            coins-=i;
        }
        return ans;
    }
};