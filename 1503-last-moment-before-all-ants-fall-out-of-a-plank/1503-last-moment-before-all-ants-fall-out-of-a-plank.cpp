class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        int ans=0;
        for(int i=0; i<max(l.size(), r.size()); i++) 
        {
            if(i<l.size()) ans=max(ans, l[i]);
            if(i<r.size()) ans=max(ans, n-r[i]);
        }
        return ans;
    }
};