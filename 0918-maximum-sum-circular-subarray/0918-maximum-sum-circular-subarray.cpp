#define ll long long int
class Solution {
public:
    ll kadane(vector<int>a,int n)
    {
        ll res=a[0];
        ll maxEnd=a[0];
        for(int i=1;i<n;i++)
        {
            maxEnd=max((ll)maxEnd+a[i],(ll)a[i]);
            res=max(res,maxEnd);
        }
        return res;
    }

    int maxSubarraySumCircular(vector<int>& arr) {
        int num=arr.size();
        ll normal=kadane(arr,num);
        if(normal<0)
        return normal;
        int sum=0;
        for(int i=0;i<num;i++)
        {
            sum+=arr[i];
            arr[i]=-arr[i];
        }
        ll circular=sum+kadane(arr,num);
        ll maxi=max(normal,circular);
        return maxi;        
    }
};