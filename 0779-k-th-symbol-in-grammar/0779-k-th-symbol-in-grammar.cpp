class Solution {
public:
    int kthGrammar( int n, int k ) {
        int left = 1, right = 1 << (n - 1);
        int ans=0;
        while (left < right) {
            int mid = left + ( right - left ) / 2 + 1;
            if (k >= mid) {
                left = mid;
                ans^=1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};