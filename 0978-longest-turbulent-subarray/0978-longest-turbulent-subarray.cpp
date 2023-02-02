class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n == 1) return 1;
        int bigger=arr[1]>arr[0];
        int ct=2;
        if(arr[1] == arr[0])
        {
            bigger=-1;
            ct=1;
        }
        int ans=ct;
        for(int i=2; i<n; i++)
        {
            if((!bigger && arr[i]<=arr[i-1]) || (bigger && arr[i]>=arr[i-1]))
            {
                if(arr[i] == arr[i-1])
                {
                    ct=1;
                    bigger=-1;
                }
                else
                {
                    ct=2;
                }
            }
            else if(bigger=-1 || (bigger && arr[i] < arr[i-1]) || (!bigger && arr[i] > arr[i-1]))
            {
                bigger=arr[i]>arr[i-1];
                ct++;
            }
            ans=max(ans, ct);
        }
        return ans;
    }
};