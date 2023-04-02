#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        int m=s.size(), n=p.size();
        sort(p.begin(), p.end());
        vector<int> ans;
        for(int i=0; i<m; i++)
        {
            if(s[i]>=success) ans.push_back(n);
            else
            {
                ll toFind=success/(s[i]*1LL);
                if(success%s[i]!=0) toFind++;
                ll ind=lower_bound(p.begin(), p.end(), toFind)-p.begin();
                ans.push_back(n-ind);
            }
        }
        return ans;
    }
};