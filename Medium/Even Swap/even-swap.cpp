//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a, int n)
        {
            if(n==1) return a;
            vector<int>pre(n-1);
            for(int i=1; i<n; i++)
            {
                pre[i-1]=a[i]+a[i-1];
            }
            int i=0, j=0;
            while(j<=n)
            {
                if(j==n)
                {
                    if(i!=n-1)
                    sort(a.begin()+i, a.end(), greater<int>());
                    break;
                }
                if(pre[j]%2==0)
                {
                    j++;
                }
                else
                {
                    sort(a.begin()+i, a.begin()+j+1, greater<int>());
                    j++;
                    i=j;
                }
            }
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends