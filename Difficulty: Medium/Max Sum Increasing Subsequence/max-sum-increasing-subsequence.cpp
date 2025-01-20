//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxSum(int cur, int prev, vector<int>&arr, vector<vector<int>>&dp) {
        if(cur==arr.size()) return 0;
        if(dp[cur][prev]!=-1) return dp[cur][prev];
        int take=0, dontTake=0;
        if(prev==0 || arr[cur]>arr[prev-1]){
            take=arr[cur]+maxSum(cur+1, cur+1, arr, dp);
        }
        dontTake=maxSum(cur+1, prev, arr, dp);
        return dp[cur][prev]=max(take, dontTake);
    }
    int maxSumIS(vector<int>& arr) {
        vector<vector<int>>dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        return maxSum(0, 0, arr, dp);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends