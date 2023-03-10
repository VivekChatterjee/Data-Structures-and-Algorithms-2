//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isValid(int pages, int students, int n, int a[])
    {
        int stud = 1, cur=0;
        for(int i=0; i<n; i++)
        {
            cur+=a[i];
            if(cur > pages)
            {
                stud++;
                cur = a[i];
            }
            if(stud > students) return 0;
        }
        return 1;
    }
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(n < m) return -1;
        int total = 0, low=INT_MIN;
        for(int i=0; i<n; i++)
        {
            total+=a[i];
            low=max(low, a[i]);
        }
        int high = total, ans = INT_MAX;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(isValid(mid, m, n, a))
            {
                ans = min(ans, mid);
                high = mid-1;
            }
            else
            low = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends