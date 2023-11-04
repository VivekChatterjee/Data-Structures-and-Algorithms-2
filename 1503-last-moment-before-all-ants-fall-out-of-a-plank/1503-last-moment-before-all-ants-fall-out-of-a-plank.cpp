class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        int ans=0;
        for(int i=0; i<l.size(); i++)
        {
            ans=max(ans, l[i]);
        }
        for(int i=0; i<r.size(); i++)
        {
            ans=max(ans, n-r[i]);
        }
        return ans;
    }
};