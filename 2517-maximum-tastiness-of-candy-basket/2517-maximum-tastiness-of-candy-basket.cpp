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
            if(count == k) break;
        }
        return (count == k);
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, h = 1e9;
        while(l < h)
        {
            int mid = l + (h - l) / 2;
            if(isValid(mid, price, k)) l = mid + 1;
            else h = mid;
        }
        return l - 1;
    }
};