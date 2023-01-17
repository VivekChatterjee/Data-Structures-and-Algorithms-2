#define ll long long int
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const ll K=1e9+7;
        // find next smaller to left and next smaller to right
        // excluding those two, current element is the min. of all subarrays
        // next smaller to right
        vector<int>v;
        vector<int> smallLeft(n), smallRight(n);
        int k=n-1;
        for(int i=n-1; i>=0; i--)
        {
            while(!v.empty() && arr[v.back()] >= arr[i])
            {
                v.pop_back();
            }
            smallRight[i]=(v.empty())? n : v.back();
            v.push_back(i);
        }
        v.clear();
        k=0;
        for(int i=0; i<n; i++)
        {
            while(!v.empty() && arr[v.back()] > arr[i])
            {
                v.pop_back();
            }
            smallLeft[i]=(v.empty())? -1 : v.back();
            v.push_back(i);
        }
        ll ans=0;
        for(int i=0; i<n; i++)
        {
            ll left=i-smallLeft[i];
            ll right=smallRight[i]-i;
            ans=(ans+(arr[i] * left * right)) % K;
        }
        return ans;
    }
};