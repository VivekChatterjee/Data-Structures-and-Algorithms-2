class Solution {
public:
    static bool cmp(pair<int, string> a, pair<int, string> b)
    {
        if(a.first == b.first) return a<b;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>m;
        for(auto i: words) m[i]++;
        vector<pair<int, string>>v;
        for(auto i: m) v.push_back({i.second, i.first});
        sort(v.begin(), v.end(), cmp);
        vector<string>ans;
        for(int i=0; i<k; i++) ans.push_back(v[i].second);
        return ans;
    }
};