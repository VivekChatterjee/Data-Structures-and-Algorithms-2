class Solution {
public:
    bool isValid(int mid, vector<int>&price, int k)
    {
        int n = price.size(), last = price[0], count = 1;
        for(int i=1; i<n; i++)
        {
            if(price[i] - last >= mid)
            {
                count++;
                last = price[i];
            }
        }
        return (count >= k);
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int l = 0, h = price[n-1] - price[0], ans = -1;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(isValid(mid, price, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return ans;
    }
};