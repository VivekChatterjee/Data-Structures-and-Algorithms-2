//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n=arr.size();
        vector<int>left(n), right(n);
        vector<int>v;
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--)
        {
            while(!v.empty() && arr[v.back()]>=arr[i])
            v.pop_back();
            if(v.empty()) right[i]=1e8;
            else right[i]=v.back();
            v.push_back(i);
        }
        v.clear();
        for(int i=0; i<n; i++)
        {
            while(!v.empty() && arr[v.back()]>=arr[i])
            v.pop_back();
            if(v.empty()) left[i]=1e8;
            else left[i]=v.back();
            v.push_back(i);
        }
        for(int i=0; i<n; i++)
        {
            if(min(left[i], right[i])==1e8) ans[i]=-1;
            else
            {
                int ld=abs(i-left[i]);
                int rd=abs(i-right[i]);
                if(ld<rd) ans[i]=left[i];       
                else if(rd<ld) ans[i]=right[i];
                else
                {
                    if(arr[left[i]]==arr[right[i]]) ans[i]=min(left[i], right[i]);
                    else 
                    {
                        ans[i]=(arr[left[i]]<arr[right[i]])? left[i] : right[i];
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends