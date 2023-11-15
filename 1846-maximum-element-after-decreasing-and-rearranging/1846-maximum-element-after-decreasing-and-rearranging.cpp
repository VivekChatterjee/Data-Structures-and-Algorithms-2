class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0]=1;
        int ans=arr[0];
        for(int i=1; i<arr.size(); i++)
        {
            if(abs(arr[i]-arr[i-1]) != 0)
            {
                arr[i]=arr[i-1]+1;
            }
        }
        return arr[arr.size()-1];
    }
};