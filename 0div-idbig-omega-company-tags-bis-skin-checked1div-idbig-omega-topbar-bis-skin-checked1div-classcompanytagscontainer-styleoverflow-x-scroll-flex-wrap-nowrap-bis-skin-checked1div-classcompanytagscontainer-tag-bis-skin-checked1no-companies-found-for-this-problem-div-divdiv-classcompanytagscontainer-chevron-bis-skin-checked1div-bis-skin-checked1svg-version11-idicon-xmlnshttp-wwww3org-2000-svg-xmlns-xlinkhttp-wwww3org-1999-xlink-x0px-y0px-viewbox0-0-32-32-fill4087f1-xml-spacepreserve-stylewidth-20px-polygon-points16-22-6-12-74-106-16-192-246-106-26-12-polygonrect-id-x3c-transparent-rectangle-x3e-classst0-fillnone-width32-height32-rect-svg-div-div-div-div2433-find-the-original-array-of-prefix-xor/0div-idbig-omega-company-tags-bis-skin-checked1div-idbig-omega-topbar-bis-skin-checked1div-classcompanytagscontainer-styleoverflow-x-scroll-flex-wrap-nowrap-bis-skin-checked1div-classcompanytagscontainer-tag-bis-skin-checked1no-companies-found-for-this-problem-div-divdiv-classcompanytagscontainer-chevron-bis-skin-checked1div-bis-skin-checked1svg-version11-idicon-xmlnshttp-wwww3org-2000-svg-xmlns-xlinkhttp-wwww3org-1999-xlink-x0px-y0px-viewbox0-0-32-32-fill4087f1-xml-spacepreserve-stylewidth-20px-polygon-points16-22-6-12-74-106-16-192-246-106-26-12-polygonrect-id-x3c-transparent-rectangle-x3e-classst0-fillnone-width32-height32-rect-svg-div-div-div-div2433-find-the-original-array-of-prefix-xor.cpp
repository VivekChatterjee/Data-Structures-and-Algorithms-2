class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans;
        int xxor = pref[0];
        ans.push_back(xxor);
        int x = 0;
        for(int i=1; i<pref.size();i++)
        {
            x = pref[i] ^ xxor;
            xxor = xxor ^ x;
            ans.push_back(x);
        }
        return ans;
    }
};