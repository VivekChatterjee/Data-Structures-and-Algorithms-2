class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& st) {
        int n=st.size();
        unordered_map<string, vector<string>>m;
        for(auto i: st)
        {
            string s=i;
            sort(s.begin(), s.end());
            m[s].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i: m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};