class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v1(26), v2(26);
        for(auto i: s) v1[i-'a']++;
        for(auto i: t) v2[i-'a']++;
        for(int i=0; i<26; i++) if(v1[i] != v2[i]) return 0;
        return s.size() == t.size();
    }
};