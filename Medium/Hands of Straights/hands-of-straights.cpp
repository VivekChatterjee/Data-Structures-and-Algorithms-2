//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int sz, vector<int> &h){
        map<int,int>mp;
        for(auto i:h)mp[i]++;
        for(auto i:mp){
            if(i.second<=0)continue;
            for(int j=1;j<sz;j++){
                mp[i.first+j]-=i.second;
                if(mp[i.first+j]<0)return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends