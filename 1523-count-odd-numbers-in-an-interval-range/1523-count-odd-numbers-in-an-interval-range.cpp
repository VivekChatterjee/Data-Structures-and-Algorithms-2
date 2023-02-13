class Solution {
public:
    int countOdds(int low, int high) {
        // int ans=0;
        // for(int i=low; i<=high; i++) if(i%2) ans++;
        // return ans;
        // O(1)
        return (high + 1) / 2 - low / 2;
    }
};