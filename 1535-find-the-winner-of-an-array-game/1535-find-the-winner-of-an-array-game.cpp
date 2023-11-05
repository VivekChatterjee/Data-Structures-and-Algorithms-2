class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size(), ans=-1, ct=0, i=1;
        while(i<n)
        {
            if(arr[0]<arr[i])
            {
                swap(arr[0], arr[i]);
            }
            if(arr[0]==ans)
            {
                ct++;
            }
            else
            {
                ans=arr[0];
                ct=1;
            }
            if(ct==k) break;
            if(i==n-1)
            {
                ans=arr[0];
            }
            i++;
        }
        return ans;
    }
};