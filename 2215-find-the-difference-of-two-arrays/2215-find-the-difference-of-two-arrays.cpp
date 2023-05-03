class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& s, vector<int>& t) {
        set<int>st(s.begin(), s.end());
        set<int>ss(t.begin(), t.end());
        set<int>z, o;
        for(int i=0; i<max(t.size(), s.size()); i++)
        {
            if(i<s.size() && !ss.count(s[i])) z.insert(s[i]);
            if(i<t.size() && !st.count(t[i])) o.insert(t[i]);
        }
        vector<int>zero, one;
        zero.assign(z.begin(), z.end());
        one.assign(o.begin(), o.end());
        return {zero, one};
    }
};