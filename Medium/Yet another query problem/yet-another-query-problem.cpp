//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, 
    vector<vector<int>> &q) 
    {
        map<int, int>m;
        vector<int>f(n), ans(num);
        for(int i=n-1; i>=0; i--)
        {
            m[a[i]]++;
            f[i]=m[a[i]];
        }
        int k=0;
        for(auto i: q)
        {
            int a=i[0];
            int b=i[1];
            int c=i[2];
            int ct=0;
            for(int j=a; j<=b; j++)
            {
                if(f[j]==c) ct++;
            }
            ans[k++]=ct;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends