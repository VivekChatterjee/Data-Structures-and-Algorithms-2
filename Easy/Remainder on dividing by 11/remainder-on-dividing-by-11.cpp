//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       int ans=0;
       int rem=0, num=0;
       int n=x.size();
       for(int i=0; i<n; i++)
       {
           rem=rem*10+(x[i]-'0');
           if(rem>=11)
           {
               rem=rem%11;
           }
       }
       return rem;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends