class Solution {
public:
    int kthGrammar( int n, int k ) {
        int left = 0, right = (1 << (n - 1)) - 1;
        int ans=0;
        while (left < right) {
            int mid = left + ( right - left ) / 2;
            if (mid >= k-1) {
                right = mid;
            }
            else
            {
                ans=!ans;
                left = mid + 1;
            }
        }
        return ans;
    }
};