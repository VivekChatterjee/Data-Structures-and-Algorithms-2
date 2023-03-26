class Solution {
public:
    int kItemsWithMaximumSum(int no, int nz, int nn, int k) {
        int ans=0;
        while(min(no, k))
        {
            ans++;
            no--;
            k--;
        }
        while(min(nz, k))
        {
            nz--;
            k--;
        }
        while(min(nn, k))
        {
            nn--;
            ans--;
            k--;
        }
        return ans;
    }
};