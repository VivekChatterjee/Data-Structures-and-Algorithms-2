class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curElement=1, count=1, n=arr.size(), cur=0;
        while(cur<n && curElement==arr[cur])
        {
            curElement++;
            cur++;
        }
        for(; count<=k; count++)
        {
            if(count==k) return curElement;
            curElement++;
            while(cur<n && curElement==arr[cur])
            {
                curElement++;
                cur++;
            }
        }
        return -1;
    }
};